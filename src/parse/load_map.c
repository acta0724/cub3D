#include "../../include/cub3d.h"

// Forward declaration
static bool is_map_line(const char *line);

static int count_map_height(const char *filename);
int parse_map(t_game *game, const char *filename);

static bool is_map_line(const char *line)
{
	int i;
	bool has_map_char;

	if (!line || line[0] == '\n' || line[0] == '\0')
		return (false);
	
	i = 0;
	has_map_char = false;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || 
			line[i] == 'N' || line[i] == 'S' || 
			line[i] == 'W' || line[i] == 'E')
		{
			has_map_char = true;
		}
		else if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			return (false); // Contains non-map characters
		}
		i++;
	}
	return (has_map_char);
}

static int count_map_height(const char *filename)
{
	int fd;
	int height;
	char *line;
	bool map_started;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_FILE);
	height = 0;
	map_started = false;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!map_started && (ft_strchr(line, '1') || ft_strchr(line, '0')))
			map_started = true;
		if (map_started && line[0] != '\n')
		{
			height++;
		}
		height++;
		free(line);
	}
	close(fd);
	if (height == 0)
		error_exit(ERR_MAP);
	return (height);
}

int parse_map(t_game *game, const char *filename)
{
	int i;
	int fd;
	char *line;
	bool map_started;

	game->height = count_map_height(filename);
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		error_exit(ERR_MAP);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_FILE);
	
	// Skip configuration lines until we reach the map
	map_started = false;
	while (!map_started)
	{
		line = get_next_line(fd);
		if (!line)
			error_exit(ERR_MAP); // Reached EOF without finding map
		
		map_started = is_map_line(line);
		free(line);
	}
	
	// Reopen the file to start from the beginning
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_FILE);
	
	// Skip configuration lines again
	map_started = false;
	while (!map_started)
	{
		line = get_next_line(fd);
		if (!line)
			error_exit(ERR_MAP);
		
		map_started = is_map_line(line);
		if (!map_started)
			free(line);
	}
	
	// Now we're at the first map line, start storing map data
	i = 0;
	while (i < game->height)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->map[i++] = line;
		
		line = get_next_line(fd);
		if (!line)
			break;
		
		// Skip non-map lines (empty lines)
		if (!is_map_line(line))
		{
			free(line);
			continue;
		}
	}
	game->map[i] = NULL;
	close(fd);
	
	// Calculate the maximum width of the map
	game->width = 0;
	i = 0;
	while (i < game->height)
	{
		int len = ft_strlen(game->map[i]);
		if (len > game->width)
			game->width = len;
		i++;
	}
	
	return (1);
}

static void validate_map(t_game *game)
{
	check_chars(game);
	check_components(game);
	// check_path(game);
}

void load_map(t_game *game, const char *filename)
{
	if (!check_file_extension(filename))
		error_exit(ERR_EXTENSION);
	if (!parse_map(game, filename))
		error_exit(ERR_MAP);
	validate_map(game);
}

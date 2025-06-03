#include "../../include/cub3d.h"

char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (&str[i]);
}

static bool	check_file_extension(const char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (false);
	return (ft_strncmp(dot, ".xpm", 5) == 0);
}

static bool	assign_texture_path(t_game *game, char *line, char *path)
{
	if (!check_file_extension(path))
		return (false);
	if (open(path, O_RDONLY) < 0)
		return (false);
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		if (game->north_texture)
		{
			return (false);
		}
		game->north_texture = path;
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		if (game->south_texture)
		{
			return (false);
		}
		game->south_texture = path;
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		if (game->west_texture)
		{
			return (false);
		}
		game->west_texture = path;
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		if (game->east_texture)
		{
			return (false);
		}
		game->east_texture = path;
	}
	else
	{
		free(path);
		return (false);
	}
	return (true);
}

bool	parse_texture(t_game *game, char *line)
{
	char	*path;
	int		i;
	char	*texture_path;

	if (!line)
		return (false);
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (!line[i])
		return (false);
	texture_path = skip_space(&line[i]);
	if (*texture_path == '\0')
		return (false);
	path = ft_strdup(texture_path);
	if (!path)
		return (false);
	if (!assign_texture_path(game, line, path))
	{
		free(path);
		return (false);
	}
	return (true);
}

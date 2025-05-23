#include "../../include/cub3d.h"

static bool is_out_of_bounds(t_game *game, int x, int y)
{
	// Safety checks to prevent segmentation fault
	if (game == NULL || game->map == NULL)
		return (true);

	// Check if y is out of bounds
	if (y < 0 || y >= game->height)
		return (true);

	// Check if the row exists
	if (game->map[y] == NULL)
		return (true);

	// Check if x is out of bounds
	if (x < 0)
		return (true);

	// Check if x is beyond the end of the row
	if (x >= (int)ft_strlen(game->map[y]))
		return (true);

	// Check if the position contains a space
	if (game->map[y][x] == ' ')
		return (true);

	return (false);
}

static void flood_fill(t_game *game, char **visited, int x, int y, bool *leak_found)
{
	static int depth = 0;
	
	// Safety checks
	if (game == NULL || visited == NULL || leak_found == NULL)
		return;
	
	depth++;
	
	// Prevent stack overflow with recursion depth limit (reduced to 500 for safety)
	if (depth > 500)
	{
		*leak_found = true;
		depth--;
		return;
	}
	
	// Early return if leak already found
	if (*leak_found)
	{
		depth--;
		return;
	}
	
	// Check if position is out of bounds
	if (is_out_of_bounds(game, x, y))
	{
		*leak_found = true;
		depth--;
		return;
	}
	
	// Additional safety check for visited array
	if (y < 0 || y >= game->height || x < 0 || x >= game->width)
	{
		*leak_found = true;
		depth--;
		return;
	}
	
	// Check if position is a wall or already visited
	if (visited[y][x] == WALL || visited[y][x] == 'V')
	{
		depth--;
		return;
	}
	
	// Mark position as visited
	visited[y][x] = 'V';
	
	// Recursively check adjacent positions
	flood_fill(game, visited, x + 1, y, leak_found);
	if (!*leak_found) flood_fill(game, visited, x - 1, y, leak_found);
	if (!*leak_found) flood_fill(game, visited, x, y + 1, leak_found);
	if (!*leak_found) flood_fill(game, visited, x, y - 1, leak_found);
	
	depth--;
}

char **copy_map(t_game *game)
{
	char **map_copy;
	int i;

	map_copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void free_map_copy(char **map_copy, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

static bool is_player_or_empty(char c)
{
	return (c == EMPTY || c == NORTH || c == SOUTH || c == EAST || c == WEST);
}

static bool check_first_last_rows(t_game *game)
{
	int j;

	// Check first row
	j = 0;
	while (j < (int)ft_strlen(game->map[0]))
	{
		if (is_player_or_empty(game->map[0][j]))
			return (false);
		j++;
	}

	// Check last row
	j = 0;
	while (j < (int)ft_strlen(game->map[game->height - 1]))
	{
		if (is_player_or_empty(game->map[game->height - 1][j]))
			return (false);
		j++;
	}

	return (true);
}

static bool check_first_last_cols(t_game *game)
{
	int i;
	int len;

	i = 0;
	while (i < game->height)
	{
		len = ft_strlen(game->map[i]);
		if (len > 0)
		{
			if (is_player_or_empty(game->map[i][0]))
				return (false);
			if (is_player_or_empty(game->map[i][len - 1]))
				return (false);
		}
		i++;
	}

	return (true);
}

static bool check_around_spaces(t_game *game)
{
	int i;
	int j;
	int len_i;
	int len_i_minus_1;
	int len_i_plus_1;

	i = 0;
	while (i < game->height)
	{
		len_i = ft_strlen(game->map[i]);
		if (i > 0)
			len_i_minus_1 = ft_strlen(game->map[i-1]);
		if (i < game->height - 1)
			len_i_plus_1 = ft_strlen(game->map[i+1]);

		j = 0;
		while (j < len_i)
		{
			if (game->map[i][j] == ' ')
			{
				if (i > 0 && j < len_i_minus_1 && is_player_or_empty(game->map[i-1][j]))
					return (false);
				if (i < game->height - 1 && j < len_i_plus_1 && is_player_or_empty(game->map[i+1][j]))
					return (false);
				if (j > 0 && is_player_or_empty(game->map[i][j-1]))
					return (false);
				if (j < len_i - 1 && is_player_or_empty(game->map[i][j+1]))
					return (false);
			}
			j++;
		}
		i++;
	}

	return (true);
}

bool check_map_borders(t_game *game)
{
	if (!check_first_last_rows(game))
		return (false);
	if (!check_first_last_cols(game))
		return (false);
	if (!check_around_spaces(game))
		return (false);
	return (true);
}

bool check_chars(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map[i]))
		{
			if (game->map[i][j] != WALL \
				&& game->map[i][j] != EMPTY \
				&& game->map[i][j] != NORTH \
				&& game->map[i][j] != EAST \
				&& game->map[i][j] != SOUTH \
				&& game->map[i][j] != WEST \
				&& game->map[i][j] != ' ')
			{
				free_game(game);
				error_exit(ERR_CHARS);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool check_components(t_game *game)
{
	int i;
	int j;
	int player_count;

	player_count = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == NORTH || game->map[i][j] == SOUTH \
				|| game->map[i][j] == EAST || game->map[i][j] == WEST)
			{
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		free_game(game);
		error_exit(ERR_PLAYER);
	}
	return (true);
}

bool normalize_map(t_game *game)
{
	int max_width = 0;
	int i, j;
	char *new_row;

	// Safety check
	if (game == NULL || game->map == NULL || game->height <= 0)
		return (false);

	// Find the maximum width
	for (i = 0; i < game->height; i++)
	{
		if (game->map[i] == NULL)
			continue;
		
		int len = ft_strlen(game->map[i]);
		if (len > max_width)
			max_width = len;
	}

	// Add padding to ensure map is properly closed
	max_width += 2;

	// Extend each row to the maximum width
	for (i = 0; i < game->height; i++)
	{
		if (game->map[i] == NULL)
			continue;
		
		int current_len = ft_strlen(game->map[i]);
		
		// Always create a new row with consistent width
		new_row = (char *)malloc(sizeof(char) * (max_width + 1));
		if (!new_row)
		{
			free_game(game);
			error_exit(ERR_MEM);
		}

		// Fill the entire row with walls for safety
		for (j = 0; j < max_width; j++)
			new_row[j] = ' ';

		// Copy existing content
		for (j = 0; j < current_len && j < max_width; j++)
			new_row[j] = game->map[i][j];

		new_row[max_width] = '\0';

		// Replace the old row
		free(game->map[i]);
		game->map[i] = new_row;
	}

	// Update game width
	game->width = max_width;
	return (true);
}

bool check_map_closed(t_game *game)
{
	char **map_copy;
	bool leak_found;

	// Normalize the map (make all rows the same length)
	normalize_map(game);

	// Check if map borders are valid
	if (!check_map_borders(game))
	{
		free_game(game);
		error_exit(ERR_MAP_BOUNDARY);
	}

	// Create a copy of the map for flood fill
	if (!(map_copy = copy_map(game)))
	{
		free_game(game);
		error_exit(ERR_MEM);
	}

	// Perform flood fill to check for leaks
	leak_found = false;
	flood_fill(game, map_copy, game->player_x, game->player_y, &leak_found);

	// If a leak was found, clean up and exit with error
	if (leak_found)
	{
		free_map_copy(map_copy, game->height);
		free_game(game);
		error_exit(ERR_MAP_LEAK);
	}

	// Clean up resources
	free_map_copy(map_copy, game->height);
	return (true);
}

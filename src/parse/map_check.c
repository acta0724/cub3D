#include "../../include/cub3d.h"

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
			free_all_lines(map_copy, i);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

bool check_chars(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
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
		while (j < game->width)
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
		return (false);
	return (true);
}

static void flood_fill(t_game *game, char **visited, int x, int y)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
	{
		game->is_map_closed = false;
		return;
	}
	if (visited[y][x] == '1' || visited[y][x] == 'V')
		return;
	if (visited[y][x] == ' ')
	{
		game->is_map_closed = false;
		return;
	}
	visited[y][x] = 'V';
	flood_fill(game, visited, x + 1, y);
	flood_fill(game, visited, x - 1, y);
	flood_fill(game, visited, x, y + 1);
	flood_fill(game, visited, x, y - 1);
}

bool check_map_closed(t_game *game)
{
	char **map_copy;

	map_copy = copy_map(game);
	if (!map_copy)
		return (false);
	flood_fill(game, map_copy, game->player_x, game->player_y);
	free_all_lines(map_copy, game->height);
	return (game->is_map_closed);
}

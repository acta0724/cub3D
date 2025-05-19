#include "../../include/cub3d.h"

void check_chars(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (i < game->height)
		{
			if (game->map[i][j] != WALL \
				&& game->map[i][j] != EMPTY \
				&& game->map[i][j] != NORTH \
				&& game->map[i][j] != EAST \
				&& game->map[i][j] != SOUTH \
				&& game->map[i][j] != WEST)
			{
				free_game(game);
				error_exit(ERR_CHARS);
			}
			j++;
		}
		i++;
	}
}

void check_components(t_game *game)
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
		}
		i++;
	}
	if (player_count != 1)
	{
		free_game(game);
		error_exit(ERR_PLAYER);
	}
}

#include "../../include/cub3d.h"

void free_map_fnished(t_game *game)
{
	int i;

	if (game->map)
	{
		i = 0;
		while (i < game->height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

void free_mlx_resources(t_game *game)
{
	if (game->mlx)
	{
		if (game->img->north)
			mlx_destroy_image(game->mlx, game->img->north);
		if (game->img->south)
			mlx_destroy_image(game->mlx, game->img->south);
		if (game->img->east)
			mlx_destroy_image(game->mlx, game->img->east);
		if (game->img->west)
			mlx_destroy_image(game->mlx, game->img->west);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		// mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void free_game(t_game *game)
{
	free_map_fnished(game);
	free_mlx_resources(game);
}
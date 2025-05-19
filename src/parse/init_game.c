#include "../../include/cub3d.h"

int load_images(t_game *game)
{
	game->img->north = mlx_xpm_file_to_image(game->mlx, "textures/north.xpm", &game->width, &game->height);
	game->img->south = mlx_xpm_file_to_image(game->mlx, "textures/south.xpm", &game->width, &game->height);
	game->img->east = mlx_xpm_file_to_image(game->mlx, "textures/east.xpm", &game->width, &game->height);
	game->img->west = mlx_xpm_file_to_image(game->mlx, "textures/west.xpm", &game->width, &game->height);
	if (!game->img->north || !game->img->south || !game->img->east || !game->img->west)
	{
		free_game(game);
		return (0);
	}
	return (1);
}

void init_game(t_game *game, const char *filename)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(ERR_MLX);
	if (!parse_map(game, filename))
	{
		free_game(game);
		error_exit(ERR_MAP);
	}
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32, "Cub3D");
	if (!game->win)
	{
		free_game(game);
		error_exit(ERR_MLX);
	}
	if (!load_images(game))
	{
		free_game(game);
		error_exit(ERR_MLX);
	}
}

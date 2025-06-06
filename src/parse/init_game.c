/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:02:49 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/06 20:42:34 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		return (false);
	game->img->north = mlx_xpm_file_to_image(game->mlx, game->north_texture,
			&img_width, &img_height);
	game->img->south = mlx_xpm_file_to_image(game->mlx, game->south_texture,
			&img_width, &img_height);
	game->img->west = mlx_xpm_file_to_image(game->mlx, game->west_texture,
			&img_width, &img_height);
	game->img->east = mlx_xpm_file_to_image(game->mlx, game->east_texture,
			&img_width, &img_height);
	if (!game->img->north || !game->img->south || !game->img->east
		|| !game->img->west)
	{
		return (false);
	}
	game->img->width = img_width;
	game->img->height = img_height;
	return (true);
}

int	render_loop(t_game *game)
{
	return (render_frame(game));
}

void	init_game(t_game *game, const char *filename)
{
	(void)filename;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(ERR_MLX);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
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
	init_raycasting(game);
	mlx_loop_hook(game->mlx, render_loop, game);
}

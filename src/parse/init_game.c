/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:02:49 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/03 21:02:50 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

#define CELL_SIZE 20

void	draw_cell(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	start_x = x * CELL_SIZE;
	start_y = y * CELL_SIZE;
	i = 0;
	while (i < CELL_SIZE)
	{
		j = 0;
		while (j < CELL_SIZE)
		{
			mlx_pixel_put(game->mlx, game->win, start_x + j, start_y + i,
				color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;
	int	size;

	start_x = x * CELL_SIZE + CELL_SIZE / 4;
	start_y = y * CELL_SIZE + CELL_SIZE / 4;
	size = CELL_SIZE / 2;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(game->mlx, game->win, start_x + j, start_y + i,
				color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, 0x000000);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == WALL)
				draw_cell(game, x, y, 0xFFFFFF);
			else if (game->map[y][x] == EMPTY)
				draw_cell(game, x, y, 0x444444);
			x++;
		}
		y++;
	}
	draw_player(game, game->player_x, game->player_y, 0xFF0000);
}

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

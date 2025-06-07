/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:40:50 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/06 20:44:00 by kmoriyam         ###   ########.fr       */
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
		x = -1;
		while (++x < WINDOW_WIDTH)
			mlx_pixel_put(game->mlx, game->win, x, y, 0x000000);
		y++;
	}
	y = 0;
	while (y < game->height)
	{
		x = -1;
		while (++x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == WALL)
				draw_cell(game, x, y, 0xFFFFFF);
			else if (game->map[y][x] == EMPTY)
				draw_cell(game, x, y, 0x444444);
		}
		y++;
	}
	draw_player(game, game->player_x, game->player_y, 0xFF0000);
}

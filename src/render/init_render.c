/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:03:23 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/06 21:14:11 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		error_exit(ERR_MEM);
	game->player->pos_x = game->player_x + 0.5;
	game->player->pos_y = game->player_y + 0.5;
	set_initial_direction(game);
	game->player->move_speed = 0.1;
	game->player->rot_speed = 0.05;
}

void	init_screen(t_game *game)
{
	game->screen = malloc(sizeof(t_img));
	if (!game->screen)
		error_exit(ERR_MEM);
	game->screen->img_ptr = mlx_new_image(game->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (!game->screen->img_ptr)
		error_exit(ERR_MLX);
	game->screen->addr = mlx_get_data_addr(game->screen->img_ptr,
			&game->screen->bits_per_pixel, &game->screen->line_length,
			&game->screen->endian);
	if (!game->screen->addr)
		error_exit(ERR_MLX);
}

void	init_raycasting(t_game *game)
{
	init_player(game);
	init_screen(game);
}

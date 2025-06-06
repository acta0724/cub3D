/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:15:56 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/06 20:19:24 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	collision_margin;
	double	x_margin;
	double	y_margin;

	collision_margin = 0.1;
	new_x = game->player->pos_x + game->player->dir_x
		* game->player->move_speed;
	new_y = game->player->pos_y + game->player->dir_y
		* game->player->move_speed;
	if (game->player->dir_x > 0)
		x_margin = collision_margin;
	else
		x_margin = -collision_margin;
	if (game->player->dir_y > 0)
		y_margin = collision_margin;
	else
		y_margin = -collision_margin;
	if (!is_wall(game, new_x + x_margin, game->player->pos_y))
		game->player->pos_x = new_x;
	if (!is_wall(game, game->player->pos_x, new_y + y_margin))
		game->player->pos_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	collision_margin;
	double	x_margin;
	double	y_margin;

	collision_margin = 0.1;
	new_x = game->player->pos_x - game->player->dir_x
		* game->player->move_speed;
	new_y = game->player->pos_y - game->player->dir_y
		* game->player->move_speed;
	if (game->player->dir_x < 0)
		x_margin = collision_margin;
	else
		x_margin = -collision_margin;
	if (game->player->dir_y < 0)
		y_margin = collision_margin;
	else
		y_margin = -collision_margin;
	if (!is_wall(game, new_x + x_margin, game->player->pos_y))
		game->player->pos_x = new_x;
	if (!is_wall(game, game->player->pos_x, new_y + y_margin))
		game->player->pos_y = new_y;
}

void	strafe_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	collision_margin;
	double	x_margin;
	double	y_margin;

	collision_margin = 0.1;
	new_x = game->player->pos_x - game->player->plane_x
		* game->player->move_speed;
	new_y = game->player->pos_y - game->player->plane_y
		* game->player->move_speed;
	if (game->player->plane_x < 0)
		x_margin = collision_margin;
	else
		x_margin = -collision_margin;
	if (game->player->plane_y < 0)
		y_margin = collision_margin;
	else
		y_margin = -collision_margin;
	if (!is_wall(game, new_x + x_margin, game->player->pos_y))
		game->player->pos_x = new_x;
	if (!is_wall(game, game->player->pos_x, new_y + y_margin))
		game->player->pos_y = new_y;
}

void	strafe_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	collision_margin;
	double	x_margin;
	double	y_margin;

	collision_margin = 0.1;
	new_x = game->player->pos_x + game->player->plane_x
		* game->player->move_speed;
	new_y = game->player->pos_y + game->player->plane_y
		* game->player->move_speed;
	if (game->player->plane_x > 0)
		x_margin = collision_margin;
	else
		x_margin = -collision_margin;
	if (game->player->plane_y > 0)
		y_margin = collision_margin;
	else
		y_margin = -collision_margin;
	if (!is_wall(game, new_x + x_margin, game->player->pos_y))
		game->player->pos_x = new_x;
	if (!is_wall(game, game->player->pos_x, new_y + y_margin))
		game->player->pos_y = new_y;
}

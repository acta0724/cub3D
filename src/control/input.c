/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:00:52 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/06 20:16:37 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_wall(t_game *game, double x, double y)
{
	if (game->map[(int)y][(int)x] == WALL)
		return (1);
	return (0);
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = game->player->dir_x;
	old_dir_y = game->player->dir_y;
	game->player->dir_x = old_dir_x * cos(-game->player->rot_speed) - old_dir_y
		* sin(-game->player->rot_speed);
	game->player->dir_y = old_dir_x * sin(-game->player->rot_speed) + old_dir_y
		* cos(-game->player->rot_speed);
	old_plane_x = game->player->plane_x;
	old_plane_y = game->player->plane_y;
	game->player->plane_x = old_plane_x * cos(-game->player->rot_speed)
		- old_plane_y * sin(-game->player->rot_speed);
	game->player->plane_y = old_plane_x * sin(-game->player->rot_speed)
		+ old_plane_y * cos(-game->player->rot_speed);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = game->player->dir_x;
	old_dir_y = game->player->dir_y;
	old_plane_x = game->player->plane_x;
	old_plane_y = game->player->plane_y;
	game->player->dir_x = old_dir_x * cos(game->player->rot_speed) - old_dir_y
		* sin(game->player->rot_speed);
	game->player->dir_y = old_dir_x * sin(game->player->rot_speed) + old_dir_y
		* cos(game->player->rot_speed);
	game->player->plane_x = old_plane_x * cos(game->player->rot_speed)
		- old_plane_y * sin(game->player->rot_speed);
	game->player->plane_y = old_plane_x * sin(game->player->rot_speed)
		+ old_plane_y * cos(game->player->rot_speed);
}

int	close_window(t_game *game)
{
	free_game(game);
	exit(0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		rotate_left(game);
	else if (keycode == KEY_D)
		rotate_right(game);
	else if (keycode == KEY_LEFT)
		rotate_left(game);
	else if (keycode == KEY_RIGHT)
		rotate_right(game);
	else if (keycode == KEY_UP)
		move_forward(game);
	else if (keycode == KEY_DOWN)
		move_backward(game);
	return (0);
}

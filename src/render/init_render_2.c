/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:13:54 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/06 21:17:59 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_north(t_game *game)
{
	game->player->dir_x = 0;
	game->player->dir_y = -1;
	game->player->plane_x = 0.66;
	game->player->plane_y = 0;
}

static void	set_south(t_game *game)
{
	game->player->dir_x = 0;
	game->player->dir_y = 1;
	game->player->plane_x = -0.66;
	game->player->plane_y = 0;
}

static void	set_east(t_game *game)
{
	game->player->dir_x = 1;
	game->player->dir_y = 0;
	game->player->plane_x = 0;
	game->player->plane_y = 0.66;
}

static void	set_west(t_game *game)
{
	game->player->dir_x = -1;
	game->player->dir_y = 0;
	game->player->plane_x = 0;
	game->player->plane_y = -0.66;
}

void	set_initial_direction(t_game *game)
{
	if (game->player_dir == NORTH)
		set_north(game);
	else if (game->player_dir == SOUTH)
		set_south(game);
	else if (game->player_dir == EAST)
		set_east(game);
	else if (game->player_dir == WEST)
		set_west(game);
}

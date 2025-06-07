/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:03:44 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/03 21:03:45 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_mlx_resources(t_game *game)
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
		free(game->mlx);
	}
}

void	free_game(t_game *game)
{
	free_init_resources(game);
	free_mlx_resources(game);
}

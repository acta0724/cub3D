/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:03:31 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/03 21:03:32 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	raycasting(t_game *game)
{
	int		x;
	t_ray	ray;

	draw_ceiling_floor(game);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray(game, &ray, x);
		perform_dda(game, &ray);
		calculate_wall(game, &ray);
		calculate_texture(game, &ray);
		draw_wall(game, &ray, x);
		x++;
	}
}

int	render_frame(t_game *game)
{
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen->img_ptr, 0, 0);
	return (0);
}

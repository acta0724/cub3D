/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:03:35 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/03 21:03:36 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_texture_color(void *img_ptr, int tex_x, int tex_y, t_game *game)
{
	char	*addr;
	int		color;
	int		bpp;
	int		size_line;
	int		endian;

	(void)game;
	addr = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	if (!addr)
		return (0);
	ft_memcpy(&color, addr + (tex_y * size_line + tex_x * (bpp / 8)),
		sizeof(int));
	return (color);
}

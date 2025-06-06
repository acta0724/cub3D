/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:09:26 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/06 21:09:34 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_map_index(t_game *game, bool *started, int i)
{
	if (game->map_start_index == -1)
		game->map_start_index = i;
	game->map_end_index = i;
	*started = true;
}

bool	get_map_height(t_game *game)
{
	if (game->map_start_index != -1 && game->map_end_index != -1)
	{
		game->height = game->map_end_index - game->map_start_index + 1;
		return (true);
	}
	return (false);
}

bool	has_map_info(char **all_lines, int i)
{
	return (!is_map_line(all_lines[i]) && (is_color_line(all_lines[i])
			|| is_texture_line(all_lines[i])));
}

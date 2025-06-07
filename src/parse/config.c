/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:02:34 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/07 14:37:04 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_game_data(t_game *game)
{
	game->north_texture = NULL;
	game->south_texture = NULL;
	game->west_texture = NULL;
	game->east_texture = NULL;
	game->map = NULL;
	game->width = -1;
	game->height = -1;
	game->floor_color.r = -1;
	game->floor_color.g = -1;
	game->floor_color.b = -1;
	game->ceiling_color.r = -1;
	game->ceiling_color.g = -1;
	game->ceiling_color.b = -1;
	game->map_start_index = -1;
	game->map_end_index = -1;
	game->is_map_closed = true;
	game->player_x = -1;
	game->player_y = -1;
	game->player_dir = '\0';
}

static bool	parse_config_line(t_game *game, char *line, bool *tex_ready,
		bool *col_ready)
{
	if (is_texture_line(line))
	{
		if (!parse_texture(game, line))
			return (false);
		if (game->north_texture && game->south_texture && game->west_texture
			&& game->east_texture)
		{
			*tex_ready = true;
		}
	}
	else if (is_color_line(line))
	{
		if (!parse_color(game, line))
			return (false);
		if (game->floor_color.r != -1 && game->floor_color.g != -1
			&& game->floor_color.b != -1 && game->ceiling_color.r != -1
			&& game->ceiling_color.g != -1 && game->ceiling_color.b != -1)
		{
			*col_ready = true;
		}
	}
	else
		return (false);
	return (true);
}

bool	parse_config_lines(t_game *game, char **all_lines, int line_count)
{
	int		i;
	bool	tex_ready;
	bool	col_ready;

	tex_ready = false;
	col_ready = false;
	i = 0;
	while (i < line_count)
	{
		if (all_lines[i][0] == '\0')
			i++;
		else if (is_map_line(all_lines[i]))
		{
			if (!tex_ready || !col_ready)
				return (false);
			i++;
		}
		else
		{
			if (!parse_config_line(game, all_lines[i], &tex_ready, &col_ready))
				return (false);
			i++;
		}
	}
	return (tex_ready && col_ready);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:02:55 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/06 21:09:24 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	find_map_indices(char **all_lines, int line_count, t_game *game)
{
	int		i;
	bool	started;

	started = false;
	i = -1;
	while (++i < line_count)
	{
		if (all_lines[i][0] == '\0')
		{
			if (started && i < line_count - 1 && is_map_line(all_lines[i + 1]))
				return (false);
		}
		else if (is_map_line(all_lines[i]))
			set_map_index(game, &started, i);
		else if (has_map_info(all_lines, i))
		{
			if (started)
				return (false);
		}
		else
			return (false);
	}
	if (get_map_height(game))
		return (true);
	return (false);
}

int	find_max_width(char **all_lines, t_game *game)
{
	int	max_width;
	int	i;
	int	len;

	max_width = 0;
	i = 0;
	while (i < game->height)
	{
		len = ft_strlen(all_lines[game->map_start_index + i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	return (max_width);
}

char	*create_padded_line(char *src, int max_width)
{
	char	*padded_line;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	padded_line = (char *)malloc(sizeof(char) * (max_width + 1));
	if (!padded_line)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		padded_line[i] = src[i];
		i++;
	}
	while (i < max_width)
	{
		padded_line[i] = ' ';
		i++;
	}
	padded_line[max_width] = '\0';
	return (padded_line);
}

char	**create_map(char **all_lines, t_game *game)
{
	char	**map;
	int		i;

	game->width = find_max_width(all_lines, game);
	map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		map[i] = create_padded_line(all_lines[game->map_start_index + i],
				game->width);
		if (!map[i])
		{
			free_all_lines(map, i);
			return (NULL);
		}
		i++;
	}
	map[game->height] = NULL;
	return (map);
}

bool	find_player(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			c = game->map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (game->player_dir != '\0')
					return (false);
				game->player_x = j;
				game->player_y = i;
				game->player_dir = c;
			}
		}
	}
	if (game->player_dir == '\0')
		return (false);
	return (true);
}

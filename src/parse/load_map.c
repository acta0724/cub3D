/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:02:52 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/07 15:25:18 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	check_file_extension(const char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (false);
	return (ft_strncmp(dot, ".cub", 5) == 0);
}

static bool	parse_map(t_game *game, const char *filename)
{
	char	**all_lines;
	int		line_count;

	init_game_data(game);
	all_lines = read_all_lines(filename, &line_count);
	if ((!all_lines || line_count == 0) || !parse_config_lines(game, all_lines,
			line_count) || !find_map_indices(all_lines, line_count, game))
	{
		free_all_lines(all_lines, line_count);
		return (false);
	}
	game->map = create_map(all_lines, game);
	if (!game->map)
	{
		free_all_lines(all_lines, line_count);
		return (false);
	}
	free_all_lines(all_lines, line_count);
	if (!find_player(game))
	{
		// free_all_lines(game->map, game->height);
		return (false);
	}
	return (true);
}

static bool	validate_map(t_game *game)
{
	if (!check_chars(game))
	{
		return (false);
	}
	if (!check_components(game))
	{
		return (false);
	}
	if (!check_map_closed(game))
	{
		return (false);
	}
	return (true);
}

void	load_map(t_game *game, const char *filename)
{
	if (!check_file_extension(filename))
	{
		error_exit(ERR_EXTENSION);
	}
	if (!parse_map(game, filename))
	{
		free_init_resources(game);
		error_exit(ERR_MAP);
	}
	if (!validate_map(game))
	{
		free_init_resources(game);
		error_exit(ERR_MAP);
	}
}

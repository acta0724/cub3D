/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:03:01 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/07 15:40:53 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (&str[i]);
}

static bool	check_file_extension(const char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (false);
	return (ft_strncmp(dot, ".xpm", 5) == 0);
}

static bool	check_textures(t_game *game, char *line, char *path)
{
	char	**texture;

	texture = NULL;
	if (ft_strncmp(line, "NO ", 3) == 0)
		texture = &game->north_texture;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		texture = &game->south_texture;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		texture = &game->west_texture;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		texture = &game->east_texture;
	if (!texture || *texture)
		return (false);
	*texture = path;
	return (true);
}

static bool	assign_texture_path(t_game *game, char *line, char *path)
{
	int	fd;

	if (!check_file_extension(path))
		return (false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	if (!check_textures(game, line, path))
		return (false);
	return (true);
}

bool	parse_texture(t_game *game, char *line)
{
	char	*path;
	int		i;
	char	*texture_path;

	if (!line)
		return (false);
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (!line[i])
		return (false);
	texture_path = skip_space(&line[i]);
	if (*texture_path == '\0')
		return (false);
	path = ft_strdup(texture_path);
	if (!path)
		return (false);
	if (!assign_texture_path(game, line, path))
	{
		free(path);
		return (false);
	}
	return (true);
}

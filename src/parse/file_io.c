/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:02:40 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/03 21:02:41 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**read_all_lines(const char *filename, int *line_count)
{
	int		fd;
	char	*line;
	char	**all_lines;
	char	**new_lines;
	int		i;

	*line_count = 0;
	all_lines = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		new_lines = (char **)malloc(sizeof(char *) * (*line_count + 2));
		if (!new_lines)
		{
			free(line);
			free_all_lines(all_lines, *line_count);
			close(fd);
			return (NULL);
		}
		i = 0;
		while (i < *line_count)
		{
			new_lines[i] = all_lines[i];
			i++;
		}
		new_lines[*line_count] = line;
		new_lines[*line_count + 1] = NULL;
		free(all_lines);
		all_lines = new_lines;
		(*line_count)++;
	}
	close(fd);
	return (all_lines);
}

void	free_all_lines(char **all_lines, int line_count)
{
	int	i;

	if (!all_lines)
		return ;
	i = 0;
	while (i < line_count)
	{
		free(all_lines[i]);
		i++;
	}
	free(all_lines);
}

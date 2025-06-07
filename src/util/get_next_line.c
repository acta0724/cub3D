/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoriyam <kmoriyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:03:49 by kmoriyam          #+#    #+#             */
/*   Updated: 2025/06/03 21:03:50 by kmoriyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h>

static char	*append_to_buffer(char *buffer, char *temp, int bytes_read)
{
	char	*new_buffer;

	temp[bytes_read] = '\0';
	if (!buffer)
		buffer = ft_strdup(temp);
	else
	{
		new_buffer = ft_strjoin(buffer, temp);
		if (!new_buffer)
		{
			free(buffer);
			return (NULL);
		}
		free(buffer);
		buffer = new_buffer;
	}
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_buffer(char *buffer, char *temp)
{
	char	*new_line_pos;
	char	*new_buffer;

	free(temp);
	new_line_pos = ft_strchr(buffer, '\n');
	if (!new_line_pos)
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_strdup(new_line_pos + 1);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	int			bytes_read;

	if (fd == -1 && buffer)
		return (free(buffer), NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer = append_to_buffer(buffer, temp, bytes_read);
		if (!buffer)
			return (free(temp), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, temp, BUFFER_SIZE);
	}
	if (bytes_read < 0 || (bytes_read == 0 && (!buffer || buffer[0] == '\0')))
		return (free(buffer), free(temp), NULL);
	line = extract_line(buffer);
	buffer = update_buffer(buffer, temp);
	return (line);
}

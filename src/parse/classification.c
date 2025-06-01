#include "../include/cub3d.h"

bool	is_map_line(const char *line)
{
	int		i;
	bool	has_map_char;

	if (!line || line[0] == '\n' || line[0] == '\0')
		return (false);
	i = 0;
	has_map_char = false;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
		{
			has_map_char = true;
		}
		else if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			return (false);
		}
		i++;
	}
	return (has_map_char);
}

bool	is_texture_line(const char *line)
{
	if (!line)
		return (false);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

bool	is_color_line(const char *line)
{
	if (!line)
		return (false);
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

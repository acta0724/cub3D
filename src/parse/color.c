#include "../../include/cub3d.h"

static void free_rgb_array(char **rgb)
{
	int i;

	if (!rgb)
		return;
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
}

static bool check_isdigits(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool parse_rgb_values(char **rgb, t_game *game, char *line)
{
	int r;
	int g;
	int b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (false);
	if (line[0] == 'F')
	{
		game->floor_color.r = r;
		game->floor_color.g = g;
		game->floor_color.b = b;
	}
	else if (line[0] == 'C')
	{
		game->ceiling_color.r = r;
		game->ceiling_color.g = g;
		game->ceiling_color.b = b;
	}
	return (true);
}

bool parse_color(t_game *game, char *line)
{
	char **rgb;
	char *color_str;

	if (!line)
		return (false);
	color_str = skip_space(line + 1);
	if (*color_str == '\0')
		return (false);
	rgb = ft_split(color_str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3] || \
		!check_isdigits(rgb[0]) || !check_isdigits(rgb[1]) || !check_isdigits(rgb[2]))
	{
		free_rgb_array(rgb);
		return (false);
	}
	if (!parse_rgb_values(rgb, game, line))
	{
		free_rgb_array(rgb);
		return (false);
	}
	free_rgb_array(rgb);
	return (true);
}

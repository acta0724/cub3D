#include "../../include/cub3d.h"

int	check_file_extension(const char *filename)
{
	char *dot;
	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (0);
	return (ft_strncmp(dot, ".cub", 5) == 0);
}

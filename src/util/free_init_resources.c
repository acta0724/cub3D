#include "../../include/cub3d.h"

void	free_init_resources(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	if (game->north_texture)
		free(game->north_texture);
	if (game->south_texture)
		free(game->south_texture);
	if (game->west_texture)
		free(game->west_texture);
	if (game->east_texture)
		free(game->east_texture);
	if (game->map)
	{
		while (i < game->height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

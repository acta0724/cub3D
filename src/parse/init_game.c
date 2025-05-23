#include "../../include/cub3d.h"

#define CELL_SIZE 20

void draw_cell(t_game *game, int x, int y, int color)
{
	int i, j;
	int start_x = x * CELL_SIZE;
	int start_y = y * CELL_SIZE;
	
	for (i = 0; i < CELL_SIZE; i++)
	{
		for (j = 0; j < CELL_SIZE; j++)
		{
			mlx_pixel_put(game->mlx, game->win, start_x + j, start_y + i, color);
		}
	}
}

void draw_player(t_game *game, int x, int y, int color)
{
	int i, j;
	int start_x = x * CELL_SIZE + CELL_SIZE / 4;
	int start_y = y * CELL_SIZE + CELL_SIZE / 4;
	int size = CELL_SIZE / 2;
	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			mlx_pixel_put(game->mlx, game->win, start_x + j, start_y + i, color);
		}
	}
}

void draw_map(t_game *game)
{
	int x, y;
	
	for (y = 0; y < WINDOW_HEIGHT; y++)
	{
		for (x = 0; x < WINDOW_WIDTH; x++)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, 0x000000);
		}
	}
	for (y = 0; y < game->height; y++)
	{
		for (x = 0; x < (int)ft_strlen(game->map[y]); x++)
		{
			if (game->map[y][x] == WALL)
				draw_cell(game, x, y, 0xFFFFFF);
			else if (game->map[y][x] == EMPTY)
				draw_cell(game, x, y, 0x444444);
		}
	}
	draw_player(game, game->player_x, game->player_y, 0xFF0000);
}

bool load_images(t_game *game)
{
	int img_width;
	int img_height;
	
	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		return (false);
	game->img->north = mlx_xpm_file_to_image(game->mlx, game->north_texture, &img_width, &img_height);
	game->img->south = mlx_xpm_file_to_image(game->mlx, game->south_texture, &img_width, &img_height);
	game->img->west = mlx_xpm_file_to_image(game->mlx, game->west_texture, &img_width, &img_height);
	game->img->east = mlx_xpm_file_to_image(game->mlx, game->east_texture, &img_width, &img_height);
	if (!game->img->north || !game->img->south || !game->img->east || !game->img->west)
	{
		return (false);
	}
	return (true);
}

int render_loop(t_game *game)
{
	draw_map(game);
	return (0);
}

void init_game(t_game *game, const char *filename)
{
	(void)filename;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(ERR_MLX);
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!game->win)
	{
		free_game(game);
		error_exit(ERR_MLX);
	}
	if (!load_images(game))
	{
		free_game(game);
		error_exit(ERR_MLX);
	}
	// draw_map(game);
	// mlx_loop_hook(game->mlx, render_loop, game);
}

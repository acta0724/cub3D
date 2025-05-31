#include "../../include/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	ft_memcpy(dst, &color, img->bits_per_pixel / 8);
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int		y;
	int		color;
	void	*tex_ptr;

	if (ray->tex_num == 0)
		tex_ptr = game->img->north;
	else if (ray->tex_num == 1)
		tex_ptr = game->img->south;
	else if (ray->tex_num == 2)
		tex_ptr = game->img->west;
	else
		tex_ptr = game->img->east;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos % game->img->height;
		ray->tex_pos += ray->tex_step;
		color = get_texture_color(tex_ptr, ray->tex_x, ray->tex_y, game);
		// if (ray->side == 1)
		// 	color = (color >> 1) & 0x7F7F7F;
		put_pixel(game->screen, x, y, color);
		y++;
	}
}

void	draw_ceiling_floor(t_game *game)
{
	int	x;
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = create_rgb(game->ceiling_color.r, game->ceiling_color.g,
			game->ceiling_color.b);
	floor_color = create_rgb(game->floor_color.r, game->floor_color.g,
			game->floor_color.b);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				put_pixel(game->screen, x, y, ceiling_color);
			else
				put_pixel(game->screen, x, y, floor_color);
			x++;
		}
		y++;
	}
}

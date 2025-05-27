#include "../../include/cub3d.h"

void	calculate_step_and_side_dist(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player->pos_y) * ray->delta_dist_y;
	}
}


void	calculate_wall(t_game *game, t_ray *ray)
{
	(void)game;
	ray->line_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;	
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->tex_num = 3;
		else
			ray->tex_num = 2;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->tex_num = 1;
		else
			ray->tex_num = 0;
	}
}

void	calculate_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = game->player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)game->img->width);
	if ((ray->side == 0 && ray->ray_dir_x < 0) ||
		(ray->side == 1 && ray->ray_dir_y > 0))
		ray->tex_x = game->img->width - ray->tex_x - 1;
	ray->tex_step = 1.0 * game->img->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - WINDOW_HEIGHT / 2 + ray->line_height / 2) * ray->tex_step;
}

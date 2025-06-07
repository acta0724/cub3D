#ifndef RENDER_H
# define RENDER_H

# include "types.h"

// init_render.c
void	init_raycasting(t_game *game);

// init_render_2.c
void	set_initial_direction(t_game *game);

// draw.c
void	put_pixel(t_img *img, int x, int y, int color);
int		create_rgb(int r, int g, int b);
void	draw_wall(t_game *game, t_ray *ray, int x);
void	draw_ceiling_floor(t_game *game);

// texture.c
int		get_texture_color(void *img_ptr, int tex_x, int tex_y, t_game *game);

// ray.c
void	init_ray(t_game *game, t_ray *ray, int x);
void	perform_dda(t_game *game, t_ray *ray);

// calc.c
void	calculate_texture(t_game *game, t_ray *ray);
void	calculate_wall(t_game *game, t_ray *ray);
void	calculate_step_and_side_dist(t_game *game, t_ray *ray);

// raycast.c
void	raycasting(t_game *game);
int		render_frame(t_game *game);

#endif
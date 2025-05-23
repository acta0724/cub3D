#ifndef TYPES_H
# define TYPES_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
} t_color;

typedef struct s_img
{
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	int 	width;
	int		height;
} t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		width;
	int		height;
	char	**map;
	// Texture paths
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	// Colors
	t_color	ceiling_color;
	t_color	floor_color;
	// Player position and direction
	int		player_x;
	int		player_y;
	char	player_dir;
	// Map indices
	int		map_start_index;
	int		map_end_index;
}	t_game;

#endif
#ifndef TYPES_H
# define TYPES_H

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
}	t_game;

#endif
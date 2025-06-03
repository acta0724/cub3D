#ifndef CUB3D_H
#define CUB3D_H

#include "utils.h"
#include "types.h"
#include "parse.h"
#include "control.h"
#include "render.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define KEY_ESC 53
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362

# define EMPTY '0'
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define ERR_ARGS "Error\nInvalid arguments. Usage: ./cub3D <map.cub>"
# define ERR_EXTENSION "Error\nFile must have .cub extension"
# define ERR_MLX "Error\nMLX initialization failed"
# define ERR_MAP "Error\nInvalid map"
# define ERR_FILE "Error\nCannot open map file"
# define ERR_CHARS "Error\nInvalid characters in map"
# define ERR_PLAYER "Error\nInvalid player position in map"
# define ERR_MEM "Error\nMemory allocation failed"
# define ERR_MAP_BOUNDARY "Error\nMap is not properly closed: Empty space or player near a boundary"
# define ERR_MAP_LEAK "Error\nMap is not closed: Found a leak in the map"

#endif
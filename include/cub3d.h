#ifndef CUB3D_H
#define CUB3D_H

#include "utils.h"
#include "types.h"
#include "parse.h"
#include "control.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define EMPTY '0'
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

# define ERR_ARGS "Error\nInvalid arguments. Usage: ./so_long <map.ber>"
# define ERR_EXTENSION "Error\nFile must have .ber extension"
# define ERR_MLX "Error\nMLX initialization failed"
# define ERR_MAP "Error\nInvalid map"
# define ERR_FILE "Error\nCannot open map file"
# define ERR_CHARS "Error\nInvalid characters in map"
# define ERR_PLAYER "Error\nInvalid player position in map"

#endif
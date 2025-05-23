#ifndef UTILS_H
# define UTILS_H

#include "types.h"

# define BUFFER_SIZE 42

void	error_exit(char *message);
void	free_map_fnished(t_game *game);
void	free_mlx_resources(t_game *game);
void	free_game(t_game *game);
char	*get_next_line(int fd);
void	debug_game_data(t_game *game);

# endif
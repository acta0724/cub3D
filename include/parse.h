# ifndef PARSE_H
# define PARSE_H

# include "types.h"

int		load_images(t_game *game);
int		check_file_extension(const char *filename);
void	load_map(t_game *game, const char *filename);
void	init_game(t_game *game, const char *filename);
int		parse_map(t_game *game, const char *filename);
void	check_chars(t_game *game);
void	check_components(t_game *game);

#endif
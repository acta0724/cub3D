# ifndef PARSE_H
# define PARSE_H

# include "types.h"
# include <stdbool.h>

int		load_images(t_game *game);
void	init_game(t_game *game, const char *filename);
bool	check_chars(t_game *game);
bool	check_components(t_game *game);
bool	check_map_closed(t_game *game);

// load_map.c
void	load_map(t_game *game, const char *filename);

// file_io.c
char	**read_all_lines(const char *filename, int *line_count);
void	free_all_lines(char **all_lines, int line_count);

// ification.c
bool	is_texture_line(const char *line);
bool	is_color_line(const char *line);
bool	is_map_line(const char *line);

// config.c
void	init_game_textures(t_game *game);
bool	parse_config_lines(t_game *game, char **all_lines, int line_count);

// map_builder.c
bool	find_map_indices(char **all_lines, int line_count, t_game *game);
int		find_max_width(char **all_lines, t_game *game);
char	*create_padded_line(char *src, int max_width);
char	**create_map(char **all_lines, t_game *game);
bool	find_player(t_game *game);

// texture.c
char	*skip_space(char *str);
bool	parse_texture(t_game *game, char *line);

// color.c
bool	parse_color(t_game *game, char *line);

#endif
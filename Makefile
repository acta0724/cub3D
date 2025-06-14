NAME		:= cub3D
LIBFT_DIR	:= ./libft
LIBFT		:= $(LIBFT_DIR)/libft.a
MLX_DIR		:= ./minilibx-linux
MLX_LIB		:= $(MLX_DIR)/libmlx.a
INCS_DIR	:= ./include
SRCS_DIR	:= ./src
OBJS_DIR	:= ./objs

CC			:= cc
CCFLAGS		:= -Wall -Wextra -Werror -I $(INCS_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR) -g
# LDFLAGS		:= -lm -L/usr/X11/lib -lX11 -lXext
MLXFLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRCS		:= $(SRCS_DIR)/main.c \
			   $(SRCS_DIR)/control/input.c \
			   $(SRCS_DIR)/control/input_2.c \
			   $(SRCS_DIR)/parse/init_game.c \
			   $(SRCS_DIR)/parse/init_game_2.c \
			   $(SRCS_DIR)/parse/load_map.c \
			   $(SRCS_DIR)/parse/map_check.c \
			   $(SRCS_DIR)/parse/color.c \
			   $(SRCS_DIR)/parse/texture.c \
			   $(SRCS_DIR)/parse/file_io.c \
			   $(SRCS_DIR)/parse/classification.c \
			   $(SRCS_DIR)/parse/map_builder.c \
			   $(SRCS_DIR)/parse/map_builder_2.c \
			   $(SRCS_DIR)/parse/config.c \
			   $(SRCS_DIR)/render/raycast.c \
			   $(SRCS_DIR)/render/init_render.c \
			   $(SRCS_DIR)/render/init_render_2.c \
			   $(SRCS_DIR)/render/texture.c \
			   $(SRCS_DIR)/render/calc.c \
			   $(SRCS_DIR)/render/draw.c \
			   $(SRCS_DIR)/render/ray.c \
			   $(SRCS_DIR)/util/error_exit.c \
			   $(SRCS_DIR)/util/free_game.c \
			   $(SRCS_DIR)/util/free_init_resources.c \
			   $(SRCS_DIR)/util/get_next_line.c


# Use the full path structure for object files to avoid name conflicts
OBJS		:= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CCFLAGS) -o $@ $^ $(MLXFLAGS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT) $(MLX_LIB)

re: fclean all

rr:
	make re && make clean

.PHONY: all clean fclean re

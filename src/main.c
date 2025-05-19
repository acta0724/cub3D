#include "../include/cub3d.h"

int	main(int argc, char** argv)
{
	t_game	game;

	if (argc != 2)
		error_exit(ERR_ARGS);
	load_map(&game, argv[1]);
	init_game(&game, argv[1]);
	// 以下はMLXのフック関数を設定する部分
	// mlx_hook(game.win, 2, 1L << 0, key_handler, &game);
	// mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	//mlx_key_hook
	//mlx_loop_hook
	//mlx_loop
	free_game(&game);
	return (0);
}
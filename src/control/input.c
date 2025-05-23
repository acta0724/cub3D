# include "../../include/cub3d.h"

int close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	exit(0);
	return (0);
}

int key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	// 以下の関数はまだ実装されていないようなのでコメントアウトしておきます
	// else if (keycode == KEY_W)
	// 	move_straight(game);
	// else if (keycode == KEY_S)
	// 	move_back(game);
	// else if (keycode == KEY_A)
	// 	move_left(game); // 視点を左に
	// else if (keycode == KEY_D)
	// 	move_right(game); // 視点を右に
	return (0);
}
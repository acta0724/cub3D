#ifndef CONTROL_H
# define CONTROL_H
# include "types.h"

// 移動関連の関数
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	strafe_left(t_game *game);
void	strafe_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

// 衝突判定関数
int		is_wall(t_game *game, double x, double y);

// ウィンドウ操作関数
int		close_window(t_game *game);
int		key_handler(int keycode, t_game *game);

#endif
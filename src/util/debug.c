#include "../../include/cub3d.h"

void	debug_game_data(t_game *game)
{
	int	i;
	int	j;

	if (!game)
		return ;
	
	// テクスチャのパスを表示
	printf("\n=== テクスチャのパス ===\n");
	printf("北: %s\n", game->north_texture ? game->north_texture : "NULL");
	printf("南: %s\n", game->south_texture ? game->south_texture : "NULL");
	printf("西: %s\n", game->west_texture ? game->west_texture : "NULL");
	printf("東: %s\n", game->east_texture ? game->east_texture : "NULL");
	
	// 色情報を表示
	printf("\n=== 色情報 ===\n");
	printf("床: RGB(%d, %d, %d)\n", 
		game->floor_color.r, game->floor_color.g, game->floor_color.b);
	printf("天井: RGB(%d, %d, %d)\n", 
		game->ceiling_color.r, game->ceiling_color.g, game->ceiling_color.b);
	
	// マップグリッドを表示
	printf("\n=== マップグリッド（ゲーム内メモリ） ===\n");
	if (!game->map)
	{
		printf("マップはNULLです\n");
		return ;
	}
	
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			printf("%c", game->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
	// プレイヤー情報を表示
	printf("\n=== プレイヤー情報 ===\n");
	printf("マップ上の位置: (%d, %d)\n", game->player_x, game->player_y);
	printf("初期向き: %c\n", game->player_dir);
	
	if (game->player)
	{
		printf("実際の位置: (%.2f, %.2f)\n", game->player->pos_x, game->player->pos_y);
		printf("方向ベクトル: (%.2f, %.2f)\n", game->player->dir_x, game->player->dir_y);
		printf("カメラ平面: (%.2f, %.2f)\n", game->player->plane_x, game->player->plane_y);
		printf("移動速度: %.2f\n", game->player->move_speed);
		printf("回転速度: %.2f\n", game->player->rot_speed);
	}
}

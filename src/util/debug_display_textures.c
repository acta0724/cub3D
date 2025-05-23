#include "../../include/cub3d.h"

/*
** テクスチャ画像をウィンドウに表示するデバッグ関数
** 4つのテクスチャを2x2のグリッドで表示します
*/
void display_texture(t_game *game, void *texture, int x, int y)
{
    int texture_width = 64;  // テクスチャの表示サイズ
    int texture_height = 64;
    
    if (texture)
    {
        mlx_put_image_to_window(game->mlx, game->win, texture, x, y);
        
        // テクスチャの周りに枠を描画
        int i;
        for (i = 0; i < texture_width; i++)
        {
            mlx_pixel_put(game->mlx, game->win, x + i, y, 0xFFFFFF);
            mlx_pixel_put(game->mlx, game->win, x + i, y + texture_height, 0xFFFFFF);
        }
        for (i = 0; i < texture_height; i++)
        {
            mlx_pixel_put(game->mlx, game->win, x, y + i, 0xFFFFFF);
            mlx_pixel_put(game->mlx, game->win, x + texture_width, y + i, 0xFFFFFF);
        }
    }
    else
    {
        // テクスチャがない場合は赤い枠を描画
        int i, j;
        for (i = 0; i < texture_width; i++)
        {
            for (j = 0; j < texture_height; j++)
            {
                if (i == 0 || i == texture_width - 1 || j == 0 || j == texture_height - 1)
                    mlx_pixel_put(game->mlx, game->win, x + i, y + j, 0xFF0000);
            }
        }
    }
}

void debug_display_textures(t_game *game)
{
    int window_width = 300;
    int window_height = 300;
    int texture_size = 64;
    int padding = 20;
    
    // 背景をクリア（黒で塗りつぶし）
    int i, j;
    for (i = 0; i < window_width; i++)
    {
        for (j = 0; j < window_height; j++)
        {
            mlx_pixel_put(game->mlx, game->win, i, j, 0x000000);
        }
    }
    
    // テクスチャ名のラベルを表示
    mlx_string_put(game->mlx, game->win, padding, padding - 10, 0xFFFFFF, "North");
    mlx_string_put(game->mlx, game->win, padding + texture_size + padding, padding - 10, 0xFFFFFF, "South");
    mlx_string_put(game->mlx, game->win, padding, padding + texture_size + padding - 10, 0xFFFFFF, "West");
    mlx_string_put(game->mlx, game->win, padding + texture_size + padding, padding + texture_size + padding - 10, 0xFFFFFF, "East");
    
    // テクスチャを表示
    display_texture(game, game->img->north, padding, padding);
    display_texture(game, game->img->south, padding + texture_size + padding, padding);
    display_texture(game, game->img->west, padding, padding + texture_size + padding);
    display_texture(game, game->img->east, padding + texture_size + padding, padding + texture_size + padding);
    
    // タイトルを表示
    mlx_string_put(game->mlx, game->win, window_width / 2 - 50, window_height - 20, 0xFFFFFF, "Texture Debug View");
}

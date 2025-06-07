#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include <math.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
} t_color;

typedef struct s_img
{
	void	*img_ptr;
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int 	width;
	int		height;
} t_img;

typedef struct s_player
{
	double	pos_x;		// プレイヤーのX座標（小数点表現）
	double	pos_y;		// プレイヤーのY座標（小数点表現）
	double	dir_x;		// 視線方向ベクトルのX成分
	double	dir_y;		// 視線方向ベクトルのY成分
	double	plane_x;	// カメラ平面ベクトルのX成分
	double	plane_y;	// カメラ平面ベクトルのY成分
	double	move_speed;	// 移動速度
	double	rot_speed;	// 回転速度
} t_player;

typedef struct s_ray
{
	double	camera_x;	// カメラ平面上のX座標
	double	ray_dir_x;	// レイの方向ベクトルのX成分
	double	ray_dir_y;	// レイの方向ベクトルのY成分
	int		map_x;		// レイが現在いるマップ座標X
	int		map_y;		// レイが現在いるマップ座標Y
	double	side_dist_x;	// 次のX側のグリッド線までの距離
	double	side_dist_y;	// 次のY側のグリッド線までの距離
	double	delta_dist_x;	// X方向の1グリッド分の距離
	double	delta_dist_y;	// Y方向の1グリッド分の距離
	double	perp_wall_dist;	// 壁までの垂直距離
	int		step_x;		// X方向の移動ステップ（1または-1）
	int		step_y;		// Y方向の移動ステップ（1または-1）
	int		hit;		// 壁に当たったかどうか
	int		side;		// どの面に当たったか（0=X面、1=Y面）
	int		line_height;	// 描画する壁の高さ
	int		draw_start;	// 描画開始Y座標
	int		draw_end;	// 描画終了Y座標
	int		tex_num;	// 使用するテクスチャ番号
	double	wall_x;	// 壁のどこに当たったか（テクスチャマッピング用）
	int		tex_x;		// テクスチャのX座標
	int		tex_y;		// テクスチャのY座標
	double	tex_pos;	// テクスチャ位置
	double	tex_step;	// テクスチャステップ
} t_ray;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_img	*screen;	// 描画用スクリーン
	t_player *player;	// プレイヤー情報
	int		width;
	int		height;
	char	**map;
	// Texture paths
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	// Colors
	t_color	ceiling_color;
	t_color	floor_color;
	// Player position and direction
	int		player_x;
	int		player_y;
	char	player_dir;
	// Map indices
	int		map_start_index;
	int		map_end_index;
	// Map validation flags
	bool	is_map_closed;
}	t_game;

#endif
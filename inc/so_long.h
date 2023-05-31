#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <../MLX42/include/MLX42/MLX42.h>

#define WIDTH 1024
#define HEIGHT 1024

# ifndef PIXEL
#  define PIXEL 64
# endif

typedef	struct s_position
{
	int x;
	int y;

} t_position;

typedef struct s_image
{
	mlx_image_t* 	img_wall;
	mlx_image_t* 	img_floor;
	mlx_image_t* 	img_collec;
	mlx_image_t* 	img_exit;
	mlx_image_t* 	img_game_over;

	mlx_image_t* 	img_player;
	mlx_image_t* 	img_player2;
	mlx_image_t* 	img_player3;
	mlx_image_t* 	img_playerL;
	mlx_image_t* 	img_playerL2;
	mlx_image_t* 	img_playerL3;

	mlx_image_t* 	img_enemy;
	mlx_image_t* 	img_enemy2;
	mlx_image_t* 	img_enemy3;
	mlx_image_t* 	img_enemyL;
	mlx_image_t* 	img_enemyL2;
	mlx_image_t* 	img_enemyL3;

	mlx_texture_t* 	texture_wall;
	mlx_texture_t* 	texture_floor;
	mlx_texture_t* 	texture_collec;
	mlx_texture_t* 	texture_exit;
	mlx_texture_t* 	texture_game_over;

	mlx_texture_t* 	texture_player;
	mlx_texture_t* 	texture_player2;
	mlx_texture_t* 	texture_player3;
	mlx_texture_t* 	texture_playerL;
	mlx_texture_t* 	texture_playerL2;
	mlx_texture_t* 	texture_playerL3;

	mlx_texture_t* 	texture_enemy;
	mlx_texture_t* 	texture_enemy2;
	mlx_texture_t* 	texture_enemy3;
	mlx_texture_t* 	texture_enemyL;
	mlx_texture_t* 	texture_enemyL2;
	mlx_texture_t* 	texture_enemyL3;

}t_image;

typedef struct s_data
{
	char    		**map;
	int    			collectible;
	int				exit;
	int				start;
	int				c;
	int				h;
	int				w;
	int				startpx;
	int				startpy;
	int				playerx;
	int				playery;
	int				enemy;
	int				enemyx;
	int				enemyy;
	int				exitx;
	int				exity;
	int 			moves;
	int				playerw;
	int				enemyw;
	int				time;
	int				cycle;
	int				game_state;
	t_position		startp;
	t_position		current;
	t_image			image;
	t_image			image2;

	mlx_t* 			mlx;
	mlx_instance_t	*player;

}   t_data;

int		ft_read_map(t_data *create, int argc, char **argv);
void	ft_init_struct(t_data *data);
void 	ft_init_pos(t_data *data);
int     ft_valid(char **map);
int 	ft_path(char **map, t_data *path);
int     ft_strchr_map(char **s, int c);
int	    ft_height(char **map);
int		ft_strchr_x(char **s, int c);
int		ft_strchr_y(char **s, int c);

void	ft_init_mlx(t_data *window, char **map);
void	ft_init_struct(t_data *data);
void 	ft_init_pos(t_data *data);
void	ft_load_texture(t_data *window);
void	ft_conv_texture(t_data *window);
void	ft_put_info(t_data *window);
void	ft_disp_img(void *param);
void 	my_keyhook(mlx_key_data_t keydata, void* param);
void	ft_player_move(int a, t_data *data);
char	*ft_put_string(t_data *window);
void	ft_render_map(void *param);
void 	ft_img2(t_data *window);
void	ft_load_player(t_data *window);
void	idle_player(t_data *window);
void 	idle_enemy(t_data *window);
void	ft_load_player_texture(t_data *data);
void	ft_load_enemy_texture(t_data *data);

void	ft_load_enemy(t_data *data);
void    ft_enemy_spawn(t_data *window);
void	enemy_move(t_data *window);
void	enemy_mover(t_data *window, int y, int x);
void	enemy_moved(t_data *window, int y, int x);
void	enemy_movel(t_data *window, int y, int x);
void	enemy_moveu(t_data *window, int y, int x);

void    game_over(void *param);
void	ft_free_map(char **s);
void	ft_delete2(t_data *window);
void	ft_free_err(void);
void    ft_free_all(t_data *data);

int	errmessage(int a);
int32_t ft_exit(void);
#endif
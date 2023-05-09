#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <../MLX42/include/MLX42/MLX42.h>

#define WIDTH 1024
#define HEIGHT 1024

typedef	struct s_position
{
	int x;
	int y;

} t_position;


typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char    		**map;
	int    			collectible;
	int				exit;
	int				start;
	int				c;
	int				h;
	int				w;
	int				startpx;
	int				startpy;
	int				currentx;
	int				currenty;
	int				playerx;
	int				playery;
	t_position		startp;
	t_position		player;
	t_position		current;
	mlx_image_t* 	img_wall;
	mlx_image_t* 	img_floor;
	mlx_image_t* 	img_collec;
	mlx_image_t* 	img_start;
	mlx_image_t* 	img_exit;
	mlx_t* 			mlx;
	mlx_texture_t* 	texture_wall;
	mlx_texture_t* 	texture_floor;
	mlx_texture_t* 	texture_collec;
	mlx_texture_t* 	texture_start;
	mlx_texture_t* 	texture_exit;
}   t_data;

void	ft_init_struct(t_data *data);
void 	ft_init_pos(t_data *data);
int     ft_valid(char **map);
int     ft_strchr_map(char **s, int c);
int	    ft_height(char **map);
int		ft_strchr_x(char **s, int c);
int		ft_strchr_y(char **s, int c);
void	ft_free_map(char **s);
void	ft_init_mlx(t_data *window, char **map);
void 	ft_init_data(t_data *window);
void	ft_draw_map(t_data *window);
void	ft_load_texture(t_data *window);
void	ft_conv_texture(t_data *window);
void	ft_disp_img(void *param);
int32_t	ft_delete(t_data *window);
void 	my_keyhook(mlx_key_data_t keydata, void* param);
void	ft_free_err(void);
void	ft_player_move(int a, t_data *data);
int	errmessage(int a);
#endif
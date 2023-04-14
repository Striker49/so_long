#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <../MLX42/include/MLX42/MLX42.h>

#define WIDTH 1024
#define HEIGHT 1024

typedef struct s_window
{
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
} t_window;

typedef	struct s_position
{
	int x;
	int y;

} t_position;


typedef struct s_data
{
	char    **map;
	int     collectible;
	int		exit;
	int		start;
	int		c;
	t_position	player;
	t_position	startp;
	t_position	current;
}   t_data;

int     ft_valid(char **map);
int     ft_strchr_map(char **s, int c);
int	    ft_height(char **map);
int		ft_strchr_x(char **s, int c);
int		ft_strchr_y(char **s, int c);
void	ft_free_map(char **s);
void 	ft_init_window(t_window *window);
void	ft_draw_map(char **map);
int32_t	ft_text_disp(t_window, int x, int y, char **map);
void	ft_disp_img(t_window window, char **map);
int32_t	ft_delete(t_window window);
void my_keyhook(mlx_key_data_t keydata, void* param);
void	ft_free_err(void);

int	errmessage(int a);
#endif
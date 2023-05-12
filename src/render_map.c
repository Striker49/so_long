/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:44:08 by seroy             #+#    #+#             */
/*   Updated: 2023/05/12 16:30:16 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Render exit
void	ft_endline(t_data *window, int y, int x)
{
	if (window->collectible == 0)
		mlx_image_to_window(window->mlx, window->img_exit, x * 64, y * 64);
	else if (window->currenty == y && window->currentx == x)
	{
		mlx_image_to_window(window->mlx, window->img_floor, x * 64, y * 64);
		mlx_image_to_window(window->mlx, window->img_start, x * 64, y * 64);					
	}
	else
	{
		mlx_image_to_window(window->mlx, window->img_floor, x * 64, y * 64);
	}

}

//Render player moves
void ft_main_game(t_data *window, int y, int x)
{
	if (window->map[y][x] == '1')
		mlx_image_to_window(window->mlx, window->img_wall, x * 64, y * 64);
	if (window->map[y][x] == '0')
		mlx_image_to_window(window->mlx, window->img_floor, x * 64, y * 64);
	if (window->map[y][x] == 'C')
		mlx_image_to_window(window->mlx, window->img_collec, x * 64, y * 64);
	if (window->map[y][x] == 'P')
	{
		mlx_image_to_window(window->mlx, window->img_floor, x * 64, y * 64);
		mlx_image_to_window(window->mlx, window->img_start, x * 64, y * 64);
	}
}

void	ft_copy_image(t_data *window)
{
	window->img_wall2 = window->img_wall;
	window->img_floor2 = window->img_floor;
	window->img_collec2 = window->img_collec;
	window->img_start2 = window->img_start;
	window->img_exit2 = window->img_exit;
	window->img_wall = window->img_wall2;
	window->img_floor = window->img_floor2;
	window->img_collec = window->img_collec2;
	window->img_start = window->img_start2;
	window->img_exit = window->img_exit2;
}

//Render map
void	ft_render_map(t_data *window)
{
	int	x;
	int	y;
	
	y = 0;
	while (window->map[y])
	{
		x = 0;
		while (window->map[y][x])
		{
			ft_main_game(window, y, x);
			if (y == window->exity && x == window->exitx)
				ft_endline(window, y, x);
			x++;
		}
		y++;
	}
	ft_copy_image(window);
}

//Render images
void	ft_disp_img(void *param)
{
	int	x;
	int	y;
	t_data *window;

	window = param;
	ft_put_info(window);
	ft_render_map(window);
}
	
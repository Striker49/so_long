/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:02:47 by seroy             #+#    #+#             */
/*   Updated: 2023/05/12 13:04:41 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Try to load the file
void	ft_load_texture(t_data *window)
{
	window->texture_wall = mlx_load_png("./temp/Bricks.png");

	window->texture_floor = mlx_load_png("./temp/grass.png");

	window->texture_collec = mlx_load_png("./temp/sus.png");

	window->texture_start = mlx_load_png("./temp/Zombie01_Idle_000.png");

	window->texture_exit = mlx_load_png("./temp/Gold1.png");

}

// Convert texture to a displayable image
void	ft_conv_texture(t_data *window)
{
	window->img_wall = mlx_texture_to_image(window->mlx, window->texture_wall);

	window->img_floor = mlx_texture_to_image(window->mlx, window->texture_floor);

	window->img_collec = mlx_texture_to_image(window->mlx, window->texture_collec);

	window->img_start = mlx_texture_to_image(window->mlx, window->texture_start);

	window->img_exit = mlx_texture_to_image(window->mlx, window->texture_exit);

}

// void ft_img2(t_data *window)
// {
// 	window->texture_wall2 = mlx_load_png("./temp/Bricks.png");

// 	window->texture_floor2 = mlx_load_png("./temp/grass.png");

// 	window->texture_collec2 = mlx_load_png("./temp/sus.png");

// 	window->texture_start2 = mlx_load_png("./temp/Zombie01_Idle_000.png");

// 	window->texture_exit2 = mlx_load_png("./temp/Gold1.png");

// 	window->img_wall2 = mlx_texture_to_image(window->mlx, window->texture_wall);

// 	window->img_floor2 = mlx_texture_to_image(window->mlx, window->texture_floor);

// 	window->img_collec2 = mlx_texture_to_image(window->mlx, window->texture_collec);

// 	window->img_start2 = mlx_texture_to_image(window->mlx, window->texture_start);

// 	window->img_exit2 = mlx_texture_to_image(window->mlx, window->texture_exit);
// }

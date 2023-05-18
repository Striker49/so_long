/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:02:47 by seroy             #+#    #+#             */
/*   Updated: 2023/05/18 15:23:13 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Try to load the file
void	ft_load_texture(t_data *window)
{
	window->image.texture_wall = mlx_load_png("./temp/Bricks.png");

	window->image.texture_floor = mlx_load_png("./temp/grass.png");

	window->image.texture_collec = mlx_load_png("./temp/sus.png");

	window->image.texture_start = mlx_load_png("./temp/Zombie01_Idle_000.png");

	window->image.texture_exit = mlx_load_png("./temp/Gold1.png");

}

// Convert texture to a displayable image
void	ft_conv_texture(t_data *window)
{
	window->image.img_wall = mlx_texture_to_image(window->mlx, window->image.texture_wall);

	window->image.img_floor = mlx_texture_to_image(window->mlx, window->image.texture_floor);

	window->image.img_collec = mlx_texture_to_image(window->mlx, window->image.texture_collec);

	window->image.img_start = mlx_texture_to_image(window->mlx, window->image.texture_start);

	window->image.img_exit = mlx_texture_to_image(window->mlx, window->image.texture_exit);

}

void ft_img2(t_data *window)
{
	window->image2.texture_wall = mlx_load_png("./temp/Bricks.png");

	window->image2.texture_floor = mlx_load_png("./temp/grass.png");

	window->image2.texture_collec = mlx_load_png("./temp/sus.png");

	window->image2.texture_start = mlx_load_png("./temp/Zombie01_Idle_000.png");

	window->image2.texture_exit = mlx_load_png("./temp/Gold1.png");

	window->image2.img_wall = mlx_texture_to_image(window->mlx, window->image.texture_wall);

	window->image2.img_floor = mlx_texture_to_image(window->mlx, window->image.texture_floor);

	window->image2.img_collec = mlx_texture_to_image(window->mlx, window->image.texture_collec);

	window->image2.img_start = mlx_texture_to_image(window->mlx, window->image.texture_start);

	window->image2.img_exit = mlx_texture_to_image(window->mlx, window->image.texture_exit);
}

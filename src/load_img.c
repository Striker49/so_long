/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:02:47 by seroy             #+#    #+#             */
/*   Updated: 2023/05/31 13:35:14 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Try to load the file
void	ft_load_texture(t_data *window)
{
	window->image.texture_wall = mlx_load_png("./temp/Bricks.png");

	window->image.texture_floor = mlx_load_png("./temp/grass.png");

	window->image.texture_collec = mlx_load_png("./temp/sus.png");

	ft_load_player_texture(window);
	
	ft_load_enemy_texture(window);

	window->image.texture_enemy = mlx_load_png("./temp/Bunny1_Idle_000.png");
	
	window->image.texture_enemyL = mlx_load_png("./temp/BunnyL.png");

	window->image.texture_exit = mlx_load_png("./temp/Gold1.png");
	
}

// Convert texture to a displayable image
void	ft_conv_texture(t_data *window)
{
	window->image.img_wall = mlx_texture_to_image(window->mlx, window->image.texture_wall);

	window->image.img_floor = mlx_texture_to_image(window->mlx, window->image.texture_floor);

	window->image.img_collec = mlx_texture_to_image(window->mlx, window->image.texture_collec);

	idle_player(window);

	idle_enemy(window);

	window->image.img_exit = mlx_texture_to_image(window->mlx, window->image.texture_exit);
	
}

void	ft_load_player_texture(t_data *data)
{
	data->image.texture_player = mlx_load_png("./temp/Zombie01_idle_000.png");

	data->image.texture_player2 = mlx_load_png("./temp/Zombie01_idle_007.png");
	
	data->image.texture_player3 = mlx_load_png("./temp/Zombie01_idle_011.png");
	
	data->image.texture_playerL = mlx_load_png("./temp/ZombieL.png");
    
	data->image.texture_playerL2 = mlx_load_png("./temp/ZombieL2.png");
    
	data->image.texture_playerL3 = mlx_load_png("./temp/ZombieL3.png");
}

void	ft_load_enemy_texture(t_data *data)
{
	data->image.texture_enemy = mlx_load_png("./temp/Bunny1_idle_000.png");

	data->image.texture_enemy2 = mlx_load_png("./temp/Bunny1_idle_005.png");
	
	data->image.texture_enemy3 = mlx_load_png("./temp/Bunny1_idle_009.png");
	
	data->image.texture_enemyL = mlx_load_png("./temp/BunnyL.png");
    
	data->image.texture_enemyL2 = mlx_load_png("./temp/BunnyL2.png");
    
	data->image.texture_enemyL3 = mlx_load_png("./temp/BunnyL3.png");
}

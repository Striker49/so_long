/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:17:13 by seroy             #+#    #+#             */
/*   Updated: 2023/05/23 16:52:03 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void idle_player(t_data *window)
{
    if (window->playerw == 0)
    {
        if (window->time >= 0 && window->time < 33)
            window->image.img_player = mlx_texture_to_image(window->mlx, window->image.texture_player);
        if (window->time >= 33 && window->time <= 66)
            window->image.img_player = mlx_texture_to_image(window->mlx, window->image.texture_player2);    
        if (window->time > 66)
            window->image.img_player = mlx_texture_to_image(window->mlx, window->image.texture_player3);
        if (window->time > 100)
            window->time = 0;
    }
    else
    {
        if (window->time >= 0 && window->time < 33)
            window->image.img_player = mlx_texture_to_image(window->mlx, window->image.texture_playerL);
        if (window->time >= 33 && window->time <= 66)
            window->image.img_player = mlx_texture_to_image(window->mlx, window->image.texture_playerL2);    
        if (window->time > 66)
            window->image.img_player = mlx_texture_to_image(window->mlx, window->image.texture_playerL3);
        if (window->time > 100)
            window->time = 0;
    }
}

void idle_enemy(t_data *window)
{
    if (window->enemyw == 0)
    {
        if (window->time >= 0 && window->time < 33)
            window->image.img_enemy = mlx_texture_to_image(window->mlx, window->image.texture_enemy);
        if (window->time >= 33 && window->time <= 66)
            window->image.img_enemy = mlx_texture_to_image(window->mlx, window->image.texture_enemy2);    
        if (window->time > 66)
            window->image.img_enemy = mlx_texture_to_image(window->mlx, window->image.texture_enemy3);
        if (window->time > 100)
            window->time = 0;
    }
    else
    {
        if (window->time >= 0 && window->time < 33)
            window->image.img_enemy = mlx_texture_to_image(window->mlx, window->image.texture_enemyL);
        if (window->time >= 33 && window->time <= 66)
            window->image.img_enemy = mlx_texture_to_image(window->mlx, window->image.texture_enemyL2);    
        if (window->time > 66)
            window->image.img_enemy = mlx_texture_to_image(window->mlx, window->image.texture_enemyL3);
        if (window->time > 100)
            window->time = 0;
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:40:29 by seroy             #+#    #+#             */
/*   Updated: 2023/06/22 14:16:19 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
	return ;
}

void	ft_free_all(t_data *data)
{
	ft_free_map(data->map);
	mlx_delete_image(data->mlx, data->image.img_game_over2);
}

//Delete image2
void	ft_delete2(t_data *window)
{
	mlx_delete_image(window->mlx, window->image2.img_wall);
	mlx_delete_image(window->mlx, window->image2.img_floor);
	mlx_delete_image(window->mlx, window->image2.img_collec);
	mlx_delete_image(window->mlx, window->image2.img_player);
	mlx_delete_image(window->mlx, window->image2.img_player2);
	mlx_delete_image(window->mlx, window->image2.img_player3);
	mlx_delete_image(window->mlx, window->image2.img_playerL);
	mlx_delete_image(window->mlx, window->image2.img_playerL2);
	mlx_delete_image(window->mlx, window->image2.img_playerL3);
	mlx_delete_image(window->mlx, window->image2.img_enemy);
	mlx_delete_image(window->mlx, window->image2.img_enemy2);
	mlx_delete_image(window->mlx, window->image2.img_enemy3);
	mlx_delete_image(window->mlx, window->image2.img_enemyL);
	mlx_delete_image(window->mlx, window->image2.img_enemyL2);
	mlx_delete_image(window->mlx, window->image2.img_enemyL3);
	mlx_delete_image(window->mlx, window->image2.img_exit);
	mlx_delete_image(window->mlx, window->image2.str1);
	mlx_delete_image(window->mlx, window->image2.str2);
	mlx_delete_image(window->mlx, window->image2.img_game_over2);
}

void	ft_delete(t_data *window)
{
	mlx_delete_image(window->mlx, window->image.img_wall);
	mlx_delete_image(window->mlx, window->image.img_floor);
	mlx_delete_image(window->mlx, window->image.img_collec);
	mlx_delete_image(window->mlx, window->image.img_player);
	mlx_delete_image(window->mlx, window->image.img_player2);
	mlx_delete_image(window->mlx, window->image.img_player3);
	mlx_delete_image(window->mlx, window->image.img_playerL);
	mlx_delete_image(window->mlx, window->image.img_playerL2);
	mlx_delete_image(window->mlx, window->image.img_playerL3);
	mlx_delete_image(window->mlx, window->image.img_enemy);
	mlx_delete_image(window->mlx, window->image.img_enemy2);
	mlx_delete_image(window->mlx, window->image.img_enemy3);
	mlx_delete_image(window->mlx, window->image.img_enemyL);
	mlx_delete_image(window->mlx, window->image.img_enemyL2);
	mlx_delete_image(window->mlx, window->image.img_enemyL3);
	mlx_delete_image(window->mlx, window->image.img_exit);
	mlx_delete_image(window->mlx, window->image.str1);
	mlx_delete_image(window->mlx, window->image.str2);
	mlx_delete_image(window->mlx, window->image2.img_game_over2);
}

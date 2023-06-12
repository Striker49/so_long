/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:40:29 by seroy             #+#    #+#             */
/*   Updated: 2023/06/12 12:20:25 by seroy            ###   ########.fr       */
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

void	ft_free_struct(t_data *data)
{
	free(data);
}

void	ft_free_all(t_data *data)
{
	ft_free_struct(data);
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
}

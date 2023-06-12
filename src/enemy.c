/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:11:34 by seroy             #+#    #+#             */
/*   Updated: 2023/06/12 12:13:59 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move(t_data *window)
{
	int	x;
	int	y;

	x = window->enemyx;
	y = window->enemyy;
	if (window->time == 25)
		window->cycle += 1;
	if (window->cycle == 2)
		enemy_mover(window, y, x);
	else if (window->cycle == 4)
		enemy_moved(window, y, x);
	else if (window->cycle == 6)
		enemy_movel(window, y, x);
	else if (window->cycle == 8)
		enemy_moveu(window, y, x);
	if (window->cycle > 8)
		window->cycle = 2;
}

void	enemy_coord(t_data *window, int y, int x)
{
	if (window->map[y][x + 1] != '1' && window->map[y][x + 1] != 'C')
	{
		window->map[y][x + 1] = 'N';
		window->enemyx = x + 1;
	}
	else if (window->map[y][x - 1] != '1' && window->map[y][x + 1] != 'C')
	{
		window->map[y][x - 1] = 'N';
		window->enemyx = x - 1;
	}
	else if (window->map[y + 1][x] != '1' && window->map[y][x + 1] != 'C')
	{
		window->map[y + 1][x] = 'N';
		window->enemyy = y + 1;
	}	
	else if (window->map[y - 1][x] != '1' && window->map[y][x + 1] != 'C')
	{
		window->map[y - 1][x] = 'N';
		window->enemyy = y - 1;
	}	
}

void	ft_enemy_spawn(t_data *window)
{
	int	x;
	int	y;

	if (window->h <= 3)
	{
		window->enemy = 0;
		return ;
	}
	x = window->exitx;
	y = window->exity;
	window->enemyx = x;
	window->enemyy = y;
	enemy_coord(window, y, x);
	window->enemy = 1;
}

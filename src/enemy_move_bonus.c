/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:42:48 by seroy             #+#    #+#             */
/*   Updated: 2023/06/12 12:18:26 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_mover(t_data *window, int y, int x)
{
	if (window->map[y][x + 1] == window->map[window->playery][window->playerx])
		game_over(window);
	if (window->map[y][x + 1] == '0' \
	&& window->map[y][x + 1] != window->map[window->exity][window->exitx])
	{
		window->map[y][x] = '0';
		window->map[y][x + 1] = 'N';
		window->enemyx += 1;
		window->enemyw = 1;
		window->cycle = 1;
	}
	else
		window->cycle = 4;
}

void	enemy_moved(t_data *window, int y, int x)
{
	if (window->map[y][x + 1] == window->map[window->playery][window->playerx])
		game_over(window);
	if (window->map[y + 1][x] == '0' \
	&& window->map[y + 1][x] != window->map[window->exity][window->exitx])
	{
		window->map[y][x] = '0';
		window->map[y + 1][x] = 'N';
		window->enemyy += 1;
		window->cycle = 3;
	}
	else
		window->cycle = 6;
}

void	enemy_movel(t_data *window, int y, int x)
{
	if (window->map[y][x + 1] == window->map[window->playery][window->playerx])
		game_over(window);
	if (window->map[y][x - 1] == '0' \
	&& window->map[y][x - 1] != window->map[window->exity][window->exitx])
	{
		window->map[y][x] = '0';
		window->map[y][x - 1] = 'N';
		window->enemyx -= 1;
		window->enemyw = 0;
		window->cycle = 5;
	}
	else
		window->cycle = 8;
}

void	enemy_moveu(t_data *window, int y, int x)
{
	if (window->map[y][x + 1] == window->map[window->playery][window->playerx])
		game_over(window);
	if (window->map[y - 1][x] == '0' \
	&& window->map[y - 1][x] != window->map[window->exity][window->exitx])
	{
		window->map[y][x] = '0';
		window->map[y - 1][x] = 'N';
		window->enemyy -= 1;
		window->cycle = 7;
	}
	else
		window->cycle = 9;
}

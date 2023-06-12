/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:25 by seroy             #+#    #+#             */
/*   Updated: 2023/06/12 15:09:23 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{
	if (data->map[data->playery - 1][data->playerx] != '1')
	{
		if (data->map[data->playery - 1][data->playerx] == 'N')
		{
			game_over(data);
		}
		if (data->map[data->playery - 1][data->playerx] == 'C')
			data->collectible -= 1;
		data->map[data->playery][data->playerx] = '0';
		data->map[data->playery - 1][data->playerx] = 'P';
		data->playery -= 1;
		data->moves += 1;
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->playery + 1][data->playerx] != '1')
	{
		if (data->map[data->playery + 1][data->playerx] == 'N')
		{
			game_over(data);
		}
		if (data->map[data->playery + 1][data->playerx] == 'C')
			data->collectible -= 1;
		data->map[data->playery][data->playerx] = '0';
		data->map[data->playery + 1][data->playerx] = 'P';
		data->playery = data->playery + 1;
		data->moves += 1;
	}
}

void	move_left(t_data *data)
{
	data->playerw = 1;
	if (data->map[data->playery][data->playerx - 1] != '1')
	{
		if (data->map[data->playery][data->playerx - 1] == 'N')
		{
			game_over(data);
		}
		if (data->map[data->playery][data->playerx - 1] == 'C')
			data->collectible -= 1;
		data->map[data->playery][data->playerx] = '0';
		data->map[data->playery][data->playerx - 1] = 'P';
		data->playerx = data->playerx - 1;
		data->moves += 1;
	}
}

void	move_right(t_data *data)
{
	data->playerw = 0;
	if (data->map[data->playery][data->playerx + 1] != '1')
	{
		if (data->map[data->playery][data->playerx + 1] == 'N')
			game_over(data);
		if (data->map[data->playery][data->playerx + 1] == 'C')
			data->collectible -= 1;
		data->map[data->playery][data->playerx] = '0';
		data->map[data->playery][data->playerx + 1] = 'P';
		data->playerx = data->playerx + 1;
		data->moves += 1;
	}
}

//Player Movement
void	ft_player_move(int a, t_data *data)
{
	if (a == 1)
		move_up(data);
	if (a == 2)
		move_down(data);
	if (a == 3)
		move_left(data);
	if (a == 4)
		move_right(data);
	if (data->collectible == 0 && data->map[data->playery][data->playerx] \
	== data->map[data->exity][data->exitx])
	{
		printf("%s%d%s", \
		"Congratulations!\nYou cleared the game in ", data->moves, " moves");
		mlx_close_window(data->mlx);
	}
}

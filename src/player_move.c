/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:25 by seroy             #+#    #+#             */
/*   Updated: 2023/05/12 12:58:44 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(t_data *data)
{
    if(data->map[data->currenty - 1][data->currentx] != '1')
    {
        if (data->map[data->currenty - 1][data->currentx] == 'C')
            data->collectible -= 1;
        data->map[data->currenty][data->currentx] = '0';
        data->map[data->currenty - 1][data->currentx] = 'P';
        data->currenty -= 1;
        data->moves += 1;
    }
}

void    move_down(t_data *data)
{
    if (data->map[data->currenty + 1][data->currentx] != '1')
    {
        if (data->map[data->currenty + 1][data->currentx] == 'C')
            data->collectible -= 1;
        data->map[data->currenty][data->currentx] = '0';
        data->map[data->currenty + 1][data->currentx] = 'P';
        data->currenty = data->currenty + 1;
        data->moves += 1;
    }
}

void    move_left(t_data *data)
{
    if (data->map[data->currenty][data->currentx - 1] != '1')
    {
        if (data->map[data->currenty][data->currentx - 1] == 'C')
            data->collectible -= 1;
        data->map[data->currenty][data->currentx] = '0';
        data->map[data->currenty][data->currentx - 1] = 'P';
        data->currentx = data->currentx - 1;
        data->moves += 1;
    }
}

void    move_right(t_data *data)
{
        if (data->map[data->currenty][data->currentx + 1] != '1')
        {
            if (data->map[data->currenty][data->currentx + 1] == 'C')
                data->collectible -= 1;
            data->map[data->currenty][data->currentx] = '0';
            data->map[data->currenty][data->currentx + 1] = 'P';
            data->currentx = data->currentx + 1;
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
	if (data->collectible == 0 && data->map[data->currenty][data->currentx] == data->map[data->exity][data->exitx])
	{
		printf("%s%d%s", "Congratulations!\nYou cleared the game in ", data->moves, " moves");
		mlx_close_window(data->mlx);

	}
}

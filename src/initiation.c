/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:05:30 by seroy             #+#    #+#             */
/*   Updated: 2023/05/12 13:36:22 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_init_struct(t_data *data)
{
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->map = 0;
	data->collectible = 0;
	data->exit = 0;
	data->start = 0;
	data->c = 0;
	data->h = 0;
	data->w = 0;
	data->startpx = 0;
	data->startpy = 0;
	data->currentx = 0;
	data->currenty = 0;
	data->currentx = 0;
	data->playery = 0;
	data->exitx = 0;
	data->exity = 0;
	data->moves = 0;

}

void ft_init_pos(t_data *data)
{
	data->startpx = ft_strchr_x(data->map, 'P');
	data->startpy = ft_strchr_y(data->map, 'P');
	data->currentx = data->startpx;
	data->currenty = data->startpy;
	data->exitx = ft_strchr_x(data->map, 'E');
	data->exity = ft_strchr_y(data->map, 'E');
	data->collectible = ft_strchr_map(data->map, 'C');
}

// Start mlx
void ft_init_mlx(t_data *window, char **map)
{	
	window->h = ft_strlen(map[0]) - 1;
	window->w = ft_height(map);
	window->mlx = mlx_init(window->h * 64, window->w * 64, "So long", true);
}

void    ft_init_game(t_data *data)
{
    ft_init_struct(data);
}
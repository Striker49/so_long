/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:05:30 by seroy             #+#    #+#             */
/*   Updated: 2023/06/28 13:33:49 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struct(t_data *data)
{
	data->map = 0;
	data->collectible = 0;
	data->exit = 0;
	data->start = 0;
	data->c = 0;
	data->h = 0;
	data->w = 0;
	data->startpx = 0;
	data->startpy = 0;
	data->playerx = 0;
	data->playery = 0;
	data->enemy = 0;
	data->enemyx = 0;
	data->enemyy = 0;
	data->playerw = 0;
	data->enemyw = 0;
	data->exitx = 0;
	data->exity = 0;
	data->moves = 0;
	data->time = 0;
	data->cycle = 0;
	data->game_state = 0;
}

void	ft_init_pos(t_data *data)
{
	data->startpx = ft_strchr_x(data->map, 'P');
	data->startpy = ft_strchr_y(data->map, 'P');
	data->playerx = data->startpx;
	data->playery = data->startpy;
	data->exitx = ft_strchr_x(data->map, 'E');
	data->exity = ft_strchr_y(data->map, 'E');
	data->collectible = ft_strchr_map(data->map, 'C');
}

// Start mlx
void	ft_init_mlx(t_data *window, char **map)
{
	window->w = ft_strlen(map[0]) - 1;
	window->h = ft_height(map);
	window->mlx = mlx_init(window->w * 64, window->h * 64, "So long", true);
	if (window->mlx == NULL)
	{
		mlx_close_window(window->mlx);
		ft_free_all(window);
		mlx_terminate(window->mlx);
	}
}

void	ft_init_game(t_data *data)
{
	ft_init_struct(data);
}

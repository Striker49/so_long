/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:08:56 by seroy             #+#    #+#             */
/*   Updated: 2023/06/12 16:07:45 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Copy map

char	**ft_copy_map(char **map)
{
	int		i;
	int		ilen;
	char	**map2;

	i = 0;
	ilen = ft_height(map) - 1;
	map2 = ft_calloc((ilen + 1), sizeof(*map2));
	if (!map2)
	{
		free(map2);
		map2 = NULL;
		return (0);
	}
	while (map[i])
	{
		map2[i] = ft_strdup(map[i]);
		i++;
	}
	return (map2);
}

int	flood_fill(char **map, int y_pos, int x_pos, int n)
{
	static int	count;
	static int	exit;

	if (map[y_pos][x_pos] == '1' || map[y_pos][x_pos] == 'N')
		return (0);
	if (map[y_pos][x_pos] == 'C')
		count++;
	if (map[y_pos][x_pos] == 'E')
		exit = 1;
	map[y_pos][x_pos] = 'N';
	flood_fill(map, y_pos - 1, x_pos, n);
	flood_fill(map, y_pos + 1, x_pos, n);
	flood_fill(map, y_pos, x_pos - 1, n);
	flood_fill(map, y_pos, x_pos + 1, n);
	if (exit != 1)
	{
		return (0);
	}
	return (count);
}

//Check if valid path

int	ft_path(char **map, t_data *path)
{
	char	**map2;
	int		x_pos;
	int		y_pos;
	int		n;

	n = '+';
	x_pos = ft_strchr_x(map, 'P');
	path->startpx = x_pos;
	y_pos = ft_strchr_y(map, 'P');
	path->startpy = y_pos;
	map2 = ft_copy_map(map);
	if (!map2)
		return (0);
	if (path->collectible != flood_fill(map2, y_pos, x_pos, n))
		return (0);
	free(map2);
	return (1);
}

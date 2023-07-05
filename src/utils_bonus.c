/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:49:57 by seroy             #+#    #+#             */
/*   Updated: 2023/06/28 13:47:18 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr_map(char **s, int c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (c == s[i][j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_strchr_x(char **s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (c == s[i][j])
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strchr_y(char **s, int c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (c == s[i][j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:49:57 by seroy             #+#    #+#             */
/*   Updated: 2023/03/20 19:13:31 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr_map(char **s, int c)
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
		while(s[i][j])
		{	
			if (c == s[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
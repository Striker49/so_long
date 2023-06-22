/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:16:16 by seroy             #+#    #+#             */
/*   Updated: 2023/06/21 17:23:10 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_put_string(t_data *window)
{
	char	*c;
	char	*m;
	char	*t;
	char	*num;
	
	num = ft_itoa(window->collectible);
	c = ft_strjoin("Brains left:", num);
	free(num);
	num = ft_itoa(window->moves);
	m = ft_strjoin("					Moves:", num);
	free(num);
	t = ft_strjoin(c, m);
	free(c);
	free(m);
	return (t);
}

void	ft_put_info(t_data *window)
{	
	char	*str1;
	char	*str2;

	str1 = ft_put_string(window);
	str2 = ft_itoa(window->collectible);
	
	window->image.str1 = mlx_put_string(window->mlx, str1, 16, 16);
	window->image.str2 = mlx_put_string(window->mlx, str2, 16, 32);
	free(str1);
	free(str2);
}

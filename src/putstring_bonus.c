/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:16:16 by seroy             #+#    #+#             */
/*   Updated: 2023/06/29 13:22:10 by seroy            ###   ########.fr       */
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
	if (!c)
		ft_errexit3(c, window);
	free(num);
	num = ft_itoa(window->moves);
	if (!num)
		ft_errexit3(num, window);
	m = ft_strjoin("					Moves:", num);
	if (!m)
		ft_errexit3(m, window);
	free(num);
	t = ft_strjoin(c, m);
	if (!t)
		ft_errexit3(t, window);
	free(c);
	free(m);
	return (t);
}

void	ft_put_info(t_data *window)
{
	char	*str1;
	char	*str2;

	str1 = ft_put_string(window);
	if (!str1)
		ft_errexit3(str1, window);
	str2 = ft_itoa(window->collectible);
	if (!str2)
		ft_errexit3(str2, window);
	window->image.str1 = mlx_put_string(window->mlx, str1, 16, 16);
	free(str1);
	window->image.str2 = mlx_put_string(window->mlx, str2, 16, 32);
	free(str2);
}

void	ft_printmove(t_data *window)
{
	char	*str;

	printf("%d\n", window->moves);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:09:37 by seroy             #+#    #+#             */
/*   Updated: 2023/07/03 16:59:14 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errmessage(int a)
{
	if (a == 1)
		printf("Error\nWrong number of objects");
	if (a == 2)
		printf("Error\nMap is not rectangular");
	if (a == 3)
		printf("Error\nMap is not surrounded by walls");
	if (a == 4)
		printf("Error\nNo path to all collectibles and/or exit");
	if (a == 5)
		printf("Error\nMap is not a .ber extension");
	if (a == 6)
		printf("Error\nMap is too big");
	if (a == 7)
		printf("Error\nUnknown objet detected in map file");
	if (a == 8)
		printf("Error\nMissing arguments");
	if (a == 9)
		printf("Error\nToo many arguments");
	exit(0);
}

void	ft_errexit(int fd, t_data *data)
{
	close (fd);
	exit (0);
}

void	ft_errexit2(int fd, char *rd, t_data *data)
{
	close (fd);
	free (rd);
	exit (0);
}

void	ft_errexit3(char *str, t_data *data)
{
	free (str);
	ft_free_all(data);
	exit (0);
}

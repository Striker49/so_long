/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:53:09 by seroy             #+#    #+#             */
/*   Updated: 2023/03/24 15:41:20 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	char		*rd;
	t_olivier	oli;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while(fd)
	{
		rd = get_next_line(fd);
		if (rd == NULL)
			break;
		i++;
		free(rd);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	oli.map = ft_calloc(i + 1, sizeof(*oli.map));
	if (!oli.map)
	{
		free(oli.map);
		return (0);
	}
	i = 0;
	while (fd)
	{
		oli.map[i] = get_next_line(fd);
		// printf("%s", oli.map[i]);
		if (oli.map[i] == NULL)
			break;
		i++;
	}
	printf("%d", ft_valid(oli.map));
	ft_free_map(oli.map);
	return (0);
}
//oublie pas de free oli.map

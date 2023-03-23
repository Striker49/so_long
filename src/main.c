/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:53:09 by seroy             #+#    #+#             */
/*   Updated: 2023/03/23 15:35:03 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// //Check if the map has an exit, a collectible and a start

// int ft_ecs(char **map)
// {
//     t_olivier	oli;

//     if (!ft_strchr_map(oli.map, 'E'))
//         return (0);
//     if (!ft_strchr_map(oli.map, 'C'))
//         return (0);
//     // if (!ft_strchr_map(map, 'S'))
//     //     return (0);
//     return (1);
// }

// //Check if the map rectangular

// int    is_rectangular(char **map)
// {
//     int	i;
//     int	j;
//     	t_olivier	oli;

//     i = 0;
//     while (oli.map[i])
//     {
//         j = 0;
//         while (map[i][j])
//             j++;
//         if (j != (int)ft_strlen(map[0]))
//             return (0);
//         i++;
//     }
//     return (1);
// }

// //Check if the map is surrounded by walls

// int ft_walls(char **map)
// {
//     int i;
//     int j;
//     	t_olivier	oli;

//     i = 0;
//     while (oli.map[i])
//     {
//         j = 0;
//         while (oli.map[i][j])
//         {
//             if (i == 0 || j == 0 || i == (int)ft_strlen(oli.map[0]) - 1 || j == (int)ft_strlen(oli.map[0]) - 1)
//             {
//                 if (oli.map[i][j] != '1')
//                     return (0);
//             }
//             j++;
//         }
//         i++;
//     }
//     return (1);
// }

// int ft_valid(char **map)
// {
//     int i;
//         t_olivier	oli;

//     // if (!ft_ecs(map))
//     //     return (0);
//     // if (!is_rectangular(map))
//     //     return (0);
//     if (!ft_walls(map))
//         return (0);
//     // if (!path(map))
//     //     return (0);
//     return (1);
// }

// char	*ft_strchr_map(char **s, int c)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		while(s[i][j])
// 		{
// 			if ((unsigned char)c == s[i][j])
// 				return ((char *)&s[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (s[i][j] == '\0' && (unsigned char)c == '\0')
// 		return ((char *)&s[i]);
// 	return (0);
// }

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
		free (rd);
	}
	close(fd);
	get_next_line(fd);
	oli.map = ft_calloc(i + 1, sizeof(*oli.map));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (fd)
	{
		rd = get_next_line(fd);
		if (rd == NULL)
			break;
		oli.map[i] = rd;
		i++;
	}
	free (rd);
	close(fd);
	printf("%d", ft_valid(oli.map));
	return (0);
}
//oublie pas de free oli.map

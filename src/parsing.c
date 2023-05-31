#include "so_long.h"

int	ft_valid_obj(char **map)
{
	int i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' \
			&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != '\n')
			{
				printf("c:%d\n", j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);

}

//Check if the map has an exit, a collectible and a start

int ft_ecp(char	**map, t_data *obj)
{
	if (ft_strchr_map(map, 'E') != 1)
		return (0);
	obj->exit = 1;
	if (!ft_strchr_map(map, 'C'))
		return (0);
	obj->collectible = ft_strchr_map(map, 'C');
	if (ft_strchr_map(map, 'P') != 1)
		return (0);
	obj->start = 1;
	// if (ft_valid_obj(map) != 1)
	// 	return (0);
	return (1);
}

//Check if the map rectangular

int    is_rectangular(char **map)
{
	int	i;
	int	j;
	int len;

	len = (int)ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j != len - 1)
			return (0);
		i++;
	}
	return (1);
}

//Check if the map is surrounded by walls

int ft_walls(char **map)
{
	int i;
	int j;
	int ilen;
	int jlen;

	i = 0;
	ilen = ft_height(map);
	jlen = (int)ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (i == 0 || j == 0 || i == ilen - 1 || j == jlen - 2)
			{
				if (map[i][j] != '1')
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int ft_valid(char **map)
{
	t_data ver;

	if (!ft_ecp(map, &ver))
		errmessage(1);
	if (!is_rectangular(map))
		errmessage(2);
	if (!ft_walls(map))
		errmessage(3);
	if (!ft_path(map, &ver))
		errmessage(4);
	if (!ft_valid_obj(map))
		errmessage(7);
	return (1);
}

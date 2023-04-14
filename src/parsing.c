#include "so_long.h"

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


//Copy map

char    **ft_copy_map(char **map)
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

int	flood_fill(char **map, int x_pos, int y_pos, int N)
{
	static int count;
	static int exit;

	if (map[x_pos][y_pos] == '1' || map[x_pos][y_pos] == N)
		return (0);
	if (map[x_pos][y_pos] == 'C')
		count++;
	if (map[x_pos][y_pos] == 'E')
		exit = 1;
	map[x_pos][y_pos] = N;
	flood_fill(map, x_pos - 1, y_pos, N);
	flood_fill(map, x_pos + 1, y_pos, N);
	flood_fill(map, x_pos, y_pos - 1, N);
	flood_fill(map, x_pos, y_pos + 1, N);
	if (exit != 1)
	{
		free(map);
		return (0);
	}
	else
		return (count);
}

//Check if valid path

int ft_path(char **map, t_data path)
{
	char	**map2;
	int		x_pos;
	int		y_pos;
	int		V;
	int		N;
    int i;

	V = '0';
	N = '+';
	x_pos = ft_strchr_x(map, 'P');
	path.startp.x = x_pos;
	y_pos = ft_strchr_y(map, 'P');
	path.startp.y = y_pos;
	map2 = ft_copy_map(map);
	if (!map2)
		return (0);
	// printf("orig:%s\n", path.map[0]);
	if (path.collectible != flood_fill(map2, x_pos, y_pos, N))
		return (0);
	free(map2);
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
	if (!ft_path(map, ver))
		errmessage(4);
	return (1);
}

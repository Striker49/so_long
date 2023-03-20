#include "so_long.h"

//Check if the map has an exit, a collectible and a start

int ft_ecs(char **map)
{
    if (!ft_strchr_map(map, 'E'))
        return (0);
    if (!ft_strchr_map(map, 'C'))
        return (0);
    // if (!ft_strchr_map(map, 'S'))
    //     return (0);
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
    if (!ft_ecs(map))
        return (0);
    if (!is_rectangular(map))
        return (0);
    if (!ft_walls(map))
        return (0);
    // if (!path(map))
    //     return (0);
    return (1);
}

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_olivier
{
    char    **map;
}   t_olivier;

int     ft_valid(char **map);
int     ft_strchr_map(char **s, int c);
int	    ft_height(char **map);

#endif
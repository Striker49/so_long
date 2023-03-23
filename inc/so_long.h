#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_olivier
{
	char    **map;
	int     collectible;
	int		exit;
	int		start;
	int		c;
}   t_olivier;

int     ft_valid(char **map);
int     ft_strchr_map(char **s, int c);
int	    ft_height(char **map);
int	ft_strchr_x(char **s, int c);
int	ft_strchr_y(char **s, int c);

#endif
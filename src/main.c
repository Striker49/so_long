// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/15 14:53:09 by seroy             #+#    #+#             */
// /*   Updated: 2023/03/28 13:18:57 by seroy            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "so_long.h"

void	ft_map_format(int argc, char **argv)
{
	int 	i;
	int 	j;
	int		ext;
	char	*s;

	if (argc < 2)
		errmessage(8);
	if (argc > 2)
		errmessage(9);
	i = 0;
	j = 0;
	s = ".ber";
	if (ft_strnstr(argv[1], s, 100) == 0)
		errmessage(5);
}

int	ft_create_map(char **argv, t_data *create, int i)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	create->map = ft_calloc(i + 1, sizeof(*create->map));
	if (!create->map)
		return (free(create->map), 0);
	i = 0;
	while (fd)
	{
		create->map[i] = get_next_line(fd);
		if (create->map[i] == NULL)
			break;
		i++;
	}
	return (0);
}

int	ft_read_map(t_data *create, int argc, char **argv)
{
	int			fd;
	int			i;
	char		*rd;

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
	ft_create_map(argv, create, i);
	return (0);
}

char	*ft_put_string(t_data *window)
{
	char *c;
	char *m;
	char *t;

	c = ft_strjoin("Brains left:", ft_itoa(window->collectible));
	m = ft_strjoin("					Moves:", ft_itoa(window->moves));
	t = ft_strjoin(c, m);
	return (t);
}

void	ft_put_info(t_data *window)
{
	mlx_put_string(window->mlx, ft_put_string(window), 16, 16);
	mlx_put_string(window->mlx, ft_itoa(window->collectible), 16, 32);
}

int	main(int argc, char**argv)
{
	t_data *window;

	window = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!window)
	{
		free(window);
		return (0);
	}
	ft_map_format(argc, argv);
	ft_init_struct(window);
	ft_read_map(window, argc, argv);
	ft_valid(window->map);
	ft_init_pos(window);
	ft_init_mlx(window, window->map);
	ft_enemy_spawn(window);
	ft_load_texture(window);
	ft_conv_texture(window);
	mlx_loop_hook(window->mlx, &ft_disp_img, window);
	mlx_key_hook(window->mlx, &my_keyhook, window);
	mlx_loop(window->mlx);
	mlx_terminate(window->mlx);
	ft_free_all(window);
}

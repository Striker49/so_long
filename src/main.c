/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:02:53 by seroy             #+#    #+#             */
/*   Updated: 2023/06/26 16:33:49 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_format(int argc, char **argv)
{
	int		i;
	int		ext;
	char	*s;

	if (argc < 2)
		errmessage(8);
	if (argc > 2)
		errmessage(9);
	s = ".ber";
	i = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + (i - 4), s, 4) != 0)
		errmessage(5);
}

int	ft_create_map(char **argv, t_data *create, int i)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	create->map = ft_calloc(i + 1, sizeof(*create->map));
	if (!create->map)
		return (free(create->map), 0);
	i = 0;
	while (fd)
	{
		create->map[i] = get_next_line(fd);
		if (create->map[i] == NULL)
			break ;
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
	while (fd)
	{
		rd = get_next_line(fd);
		if (rd == NULL)
			break ;
		i++;
		free(rd);
	}
	close(fd);
	ft_create_map(argv, create, i);
	return (0);
}

int	main(int argc, char**argv)
{
	t_data	window;

	ft_map_format(argc, argv);
	ft_init_struct(&window);
	ft_read_map(&window, argc, argv);
	ft_valid(window.map);
	ft_init_pos(&window);
	ft_init_mlx(&window, window.map);
	ft_enemy_spawn(&window);
	ft_load_texture(&window);
	ft_conv_texture(&window);
	mlx_loop_hook(window.mlx, &ft_disp_img, &window);
	mlx_key_hook(window.mlx, &my_keyhook, &window);
	mlx_close_hook(window.mlx, &close_game, &window);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	ft_free_all(&window);
	return (EXIT_SUCCESS);
}

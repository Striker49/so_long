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

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	char		*rd;
	t_data		create;

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
	create.map = ft_calloc(i + 1, sizeof(*create.map));
	if (!create.map)
	{
		free(create.map);
		return (0);
	}
	i = 0;
	while (fd)
	{
		create.map[i] = get_next_line(fd);
		if (create.map[i] == NULL)
			break;
		i++;
	}
	ft_valid(create.map);
	ft_draw_map(create, create.map);
	ft_free_map(create.map);
	return (0);
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_load_texture(t_data *window)
{
	// Try to load the file
	window->texture_wall = mlx_load_png("./temp/Bricks.png");
	if (!window->texture_wall)
        error();
	window->texture_floor = mlx_load_png("./temp/grass.png");
	if (!window->texture_floor)
        error();
	window->texture_collec = mlx_load_png("./temp/sus.png");
	if (!window->texture_collec)
        error();
	window->texture_start = mlx_load_png("./temp/Zombie01_Idle_000.png");
	if (!window->texture_start)
        error();
	window->texture_exit = mlx_load_png("./temp/Gold1.png");
	if (!window->texture_exit)
        error();
}

void	ft_draw_map(t_data window, char **map)
{
	int h;
	int	w;

	h = ft_strlen(map[0]) - 1;
	w = ft_height(map);

	// Start mlx
	window.mlx = mlx_init(h * 64, w * 64, "So long", true);
	if (!window.mlx)
        error();
	ft_load_texture(&window);
	ft_text_disp(window, map);
}

void	ft_conv_texture(t_data *window)
{
	// Convert texture to a displayable image
	window->img_wall = mlx_texture_to_image(window->mlx, window->texture_wall);
	if (!window->img_wall)
        error();
	window->img_floor = mlx_texture_to_image(window->mlx, window->texture_floor);
	if (!window->img_floor)
        error();
	window->img_collec = mlx_texture_to_image(window->mlx, window->texture_collec);
	if (!window->img_collec)
        error();
	window->img_start = mlx_texture_to_image(window->mlx, window->texture_start);
	if (!window->img_start)
        error();
	window->img_exit = mlx_texture_to_image(window->mlx, window->texture_exit);
	if (!window->img_exit)
        error();
}

int32_t	ft_text_disp(t_data window, char **map)
{
	ft_conv_texture(&window);
	ft_disp_img(window, map);
	mlx_key_hook(window.mlx, &my_keyhook, NULL);
	mlx_loop(window.mlx);
	ft_delete(window);
	return (0);
}

void	ft_player_move(int a)
{
	t_data	*data;

	// printf("%s\n", data->map[4]);

	if (data->startp.x != 0)
	{
		data->current.x = data->startp.x;
		data->current.y = data->startp.y;
	}
	data->startp.x = 0;
	if (a == 1)
	{
		if (data->map[data->current.y - 1][data->player.x] != '1')
		{
			data->map[data->current.y][data->current.x] = '0';
			data->map[data->current.y - 1][data->player.x] = 'P';
			data->current.y = data->current.y - 1;
		}
	}
	if (a == 2)
	{
		if (data->map[data->current.y + 1][data->player.x] != '1')
		{
			data->map[data->current.y][data->current.x] = '0';
			data->map[data->current.y + 1][data->player.x] = 'P';
			data->current.y = data->current.y + 1;
		}
	}
	if (a == 3)
	{
		if (data->map[data->current.y][data->player.x - 1] != '1')
		{
			data->map[data->current.y][data->current.x] = '0';
			data->map[data->current.y][data->player.x - 1] = 'P';
			data->player.x = data->player.x - 1;
		}
	}
	if (a == 4)
	{
		if (data->map[data->current.y][data->player.x + 1] != '1')
		{
			data->map[data->current.y][data->current.x] = '0';
			data->map[data->current.y][data->player.x + 1] = 'P';
			data->player.x = data->player.x + 1;
		}
	}
	ft_disp_img(*data, data->map);
	
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data		change;

	// If we PRESS the 'up' key, go up.
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		ft_player_move(1);

	// If we PRESS the 'down' key, go down.
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		ft_player_move(2);

	// If we PRESS the 'left' key, go left.
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_player_move(3);

	// If we PRESS the 'right' key, go right.
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_player_move(4);

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	ft_disp_img(change, change.map);
}


void	ft_disp_img(t_data window, char **map)
{
	int	x;
	int	y;
	// Display the image
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(window.mlx, window.img_wall, x * 64, y * 64) < 0)
        			error();
			}
			if (map[y][x] == '0')
			{
				if (mlx_image_to_window(window.mlx, window.img_floor, x * 64, y * 64) < 0)
        			error();
			}
			if (map[y][x] == 'C')
			{
				if (mlx_image_to_window(window.mlx, window.img_collec, x * 64, y * 64) < 0)
        			error();
			}
			if (map[y][x] == 'P')
			{
				if (mlx_image_to_window(window.mlx, window.img_start, x * 64, y * 64) < 0)
        			error();
			}
			if (map[y][x] == 'E')
			{
				if (mlx_image_to_window(window.mlx, window.img_exit, x * 64, y * 64) < 0)
        			error();
			}
			x++;
		}
		y++;
	}
	// mlx_key_hook(window.mlx, &my_keyhook, NULL);
}
	

int32_t	ft_delete(t_data window)
{
	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(window.mlx, window.img_wall);
	mlx_delete_image(window.mlx, window.img_floor);
	mlx_delete_image(window.mlx, window.img_collec);
	mlx_delete_image(window.mlx, window.img_start);
	mlx_delete_image(window.mlx, window.img_exit);
	mlx_delete_texture(window.texture_wall);
	mlx_delete_texture(window.texture_floor);
	mlx_delete_texture(window.texture_collec);
	mlx_delete_texture(window.texture_start);
	mlx_delete_texture(window.texture_exit);
	mlx_terminate(window.mlx);
	return (EXIT_SUCCESS);
}
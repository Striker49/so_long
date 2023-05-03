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
	ft_draw_map(create);
	ft_free_map(create.map);
	return (0);
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Try to load the file
void	ft_load_texture(t_data *window)
{
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

// Start mlx
void ft_init_mlx(t_data *window, char **map)
{	
	window->h = ft_strlen(map[0]) - 1;
	window->w = ft_height(map);
	window->mlx = mlx_init(window->h * 64, window->w * 64, "So long", true);
	if (!window->mlx)
        error();
}

void	ft_draw_map(t_data window)
{
	// window.startp.x = ft_strchr_x(window.map, 'P');
	// window.startp.y = ft_strchr_y(window.map, 'P');

	// printf("x:%d\ny:%d\n", window.startp.x, window.startp.y);

	ft_init_mlx(&window, window.map);
	ft_load_texture(&window);
	ft_conv_texture(&window);	
	ft_disp_img(window);
	mlx_key_hook(window.mlx, &my_keyhook, NULL);
	mlx_loop(window.mlx);
	ft_delete(window);
}

// Convert texture to a displayable image
void	ft_conv_texture(t_data *window)
{
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

//Player Movement
void	ft_player_move(int a, t_data *data)
{
	data->startp.x = ft_strchr_x(data->map, 'P');
	data->startp.y = ft_strchr_y(data->map, 'P');
	printf("x:%d\ny:%d\n", data->startp.x, data->startp.y);

	if (data->startpx != 0)
	{
		data->currentx = data->startpx;
		data->currenty = data->startpy;
	}
	data->startpx = 0;
	if (a == 1)
	{
		if (data->map[data->currenty - 1][data->playerx] != '1')
		{
			data->map[data->currenty][data->currentx] = '0';
			data->map[data->currenty - 1][data->playerx] = 'P';
			data->currenty = data->currenty - 1;
		}
	}
	if (a == 2)
	{
		if (data->map[data->currenty + 1][data->playerx] != '1')
		{
			data->map[data->currenty][data->currentx] = '0';
			data->map[data->currenty + 1][data->playerx] = 'P';
			data->currenty = data->currenty + 1;
		}
	}
	if (a == 3)
	{
		if (data->map[data->currenty][data->playerx - 1] != '1')
		{
			data->map[data->currenty][data->currentx] = '0';
			data->map[data->currenty][data->playerx - 1] = 'P';
			data->playerx = data->playerx - 1;
		}
	}
	if (a == 4)
	{
		if (data->map[data->currenty][data->playerx + 1] != '1')
		{
			data->map[data->currenty][data->currentx] = '0';
			data->map[data->currenty][data->playerx + 1] = 'P';
			data->playerx = data->playerx + 1;
		}
	}
	ft_disp_img(*data);
	
}

//Key Pressed
void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data		change;

	// If we PRESS the 'up' key, go up.
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		ft_player_move(1, &change);

	// If we PRESS the 'down' key, go down.
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		ft_player_move(2, &change);

	// If we PRESS the 'left' key, go left.
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_player_move(3, &change);

	// If we PRESS the 'right' key, go right.
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_player_move(4, &change);

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	ft_disp_img(change);
}

//Display images
void	ft_disp_img(t_data window)
{
	int	x;
	int	y;

	y = 0;
	while (window.map[y])
	{
		x = 0;
		while (window.map[y][x])
		{
			if (window.map[y][x] == '1')
			{
				if (mlx_image_to_window(window.mlx, window.img_wall, x * 64, y * 64) < 0)
        			error();
			}
			if (window.map[y][x] == '0')
			{
				if (mlx_image_to_window(window.mlx, window.img_floor, x * 64, y * 64) < 0)
        			error();
			}
			if (window.map[y][x] == 'C')
			{
				if (mlx_image_to_window(window.mlx, window.img_collec, x * 64, y * 64) < 0)
        			error();
			}
			if (window.map[y][x] == 'P')
			{
				if (mlx_image_to_window(window.mlx, window.img_start, x * 64, y * 64) < 0)
        			error();
			}
			if (window.map[y][x] == 'E')
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
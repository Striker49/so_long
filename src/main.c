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
	t_data		*create;

	create = (t_data *)ft_calloc(1, sizeof(t_data));
	ft_init_struct(create);
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
	create->map = ft_calloc(i + 1, sizeof(*create->map));
	if (!create->map)
	{
		free(create->map);
		return (0);
	}
	i = 0;
	while (fd)
	{
		create->map[i] = get_next_line(fd);
		if (create->map[i] == NULL)
			break;
		i++;
	}
	ft_valid(create->map);
	ft_init_pos(create);
	ft_draw_map(create);
	ft_free_map(create->map);
	return (0);
}

void	ft_init_struct(t_data *data)
{
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->map = 0;
	data->collectible = ft_strchr_map(data->map, 'C');
	data->exit = 0;
	data->start = 0;
	data->c = 0;
	data->h = 0;
	data->w = 0;
	data->startpx = 0;
	data->startpy = 0;
	data->currentx = 0;
	data->currenty = 0;
	data->currentx = 0;
	data->playery = 0;
	data->exitx = 0;
	data->exity = 0;
	data->moves = 0;

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

void ft_init_pos(t_data *data)
{
	data->startpx = ft_strchr_x(data->map, 'P');
	data->startpy = ft_strchr_y(data->map, 'P');
	data->currentx = data->startpx;
	data->currenty = data->startpy;
	data->exitx = ft_strchr_x(data->map, 'E');
	data->exity = ft_strchr_x(data->map, 'E');
	data->collectible = ft_strchr_map(data->map, 'C');

}

void ft_img2(t_data *window)
{
	window->texture_wall2 = mlx_load_png("./temp/Bricks.png");
	if (!window->texture_wall2)
        error();
	window->texture_floor2 = mlx_load_png("./temp/grass.png");
	if (!window->texture_floor2)
        error();
	window->texture_collec2 = mlx_load_png("./temp/sus.png");
	if (!window->texture_collec2)
        error();
	window->texture_start2 = mlx_load_png("./temp/Zombie01_Idle_000.png");
	if (!window->texture_start2)
        error();
	window->texture_exit2 = mlx_load_png("./temp/Gold1.png");
	if (!window->texture_exit2)
        error();
	window->img_wall2 = mlx_texture_to_image(window->mlx, window->texture_wall);
	if (!window->img_wall2)
        error();
	window->img_floor2 = mlx_texture_to_image(window->mlx, window->texture_floor);
	if (!window->img_floor2)
        error();
	window->img_collec2 = mlx_texture_to_image(window->mlx, window->texture_collec);
	if (!window->img_collec2)
        error();
	window->img_start2 = mlx_texture_to_image(window->mlx, window->texture_start);
	if (!window->img_start2)
        error();
	window->img_exit2 = mlx_texture_to_image(window->mlx, window->texture_exit);
	if (!window->img_exit2)
        error();
}

void	ft_draw_map(t_data *window)
{

	printf("c:%d\n", window->collectible);

	ft_init_mlx(window, window->map);
	ft_load_texture(window);
	ft_conv_texture(window);
	ft_img2(window);
	mlx_loop_hook(window->mlx, &ft_disp_img, window);
	mlx_key_hook(window->mlx, &my_keyhook, window);
	mlx_loop(window->mlx);
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
	if (a == 1)
	{
		if(data->map[data->currenty - 1][data->currentx] != '1')
		{
			if (data->map[data->currenty - 1][data->currentx] == 'C')
				data->collectible -= 1;
			if (data->map[data->currenty][data->currentx] != 'E')
				data->map[data->currenty][data->currentx] = '0';
			data->map[data->currenty - 1][data->currentx] = 'P';
			data->currenty -= 1;
			data->moves += 1;
		}
	}
		
	if (a == 2)
	{
		if (data->map[data->currenty + 1][data->currentx] != '1')
		{
			if (data->map[data->currenty + 1][data->currentx] == 'C')
				data->collectible -= 1;
			if (data->map[data->currenty][data->currentx] != 'E')
				data->map[data->currenty][data->currentx] = '0';
			data->map[data->currenty + 1][data->currentx] = 'P';
			data->currenty = data->currenty + 1;
			data->moves += 1;
		}
	}
	if (a == 3)
	{
		if (data->map[data->currenty][data->currentx - 1] != '1')
		{
			if (data->map[data->currenty][data->currentx - 1] == 'C')
				data->collectible -= 1;
			if (data->map[data->currenty][data->currentx] != 'E')
				data->map[data->currenty][data->currentx] = '0';
			data->map[data->currenty][data->currentx - 1] = 'P';
			data->currentx = data->currentx - 1;
			data->moves += 1;
		}
	}
	if (a == 4)
	{
		if (data->map[data->currenty][data->currentx + 1] != '1')
		{
			if (data->map[data->currenty][data->currentx + 1] == 'C')
				data->collectible -= 1;
			if (data->map[data->currenty][data->currentx] != 'E')
				data->map[data->currenty][data->currentx] = '0';
			data->map[data->currenty][data->currentx + 1] = 'P';
			data->currentx = data->currentx + 1;
			data->moves += 1;
		}
	}
	if (data->collectible == 0 && data->map[data->currenty][data->currentx] == 'E')
		ft_delete(data);

	
}

//Key Pressed
void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data		*change;

	change = param;

	// If we PRESS the 'up' key, go up.
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		// printf("av%d", change->currenty);
		ft_player_move(1, change);
	}

	// If we PRESS the 'down' key, go down.
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		ft_player_move(2, change);

	// If we PRESS the 'left' key, go left.
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_player_move(3, change);

	// If we PRESS the 'right' key, go right.
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_player_move(4, change);

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
	// ft_disp_img(change);
}

char	*ft_put_string(t_data *window)
{
	char *c;
	char *m;
	char *t;

	c = ft_strjoin("Collectibles left:", ft_itoa(window->collectible));
	m = ft_strjoin("					Moves:", ft_itoa(window->moves));
	t = ft_strjoin(c, m);
	return (t);
}

//Display images
void	ft_disp_img(void *param)
{
	int	x;
	int	y;
	t_data *window;

	window = param;
	mlx_put_string(window->mlx, ft_put_string(window), 16, 16);
	mlx_put_string(window->mlx, ft_itoa(window->collectible), 16, 32);
	y = 0;
	while (window->map[y])
	{
		x = 0;
		while (window->map[y][x])
		{
			if (window->map[y][x] == '1')
			{
				if (mlx_image_to_window(window->mlx, window->img_wall, x * 64, y * 64) < 0)
        			error();
			}
			if (window->map[y][x] == '0')
			{
				if (mlx_image_to_window(window->mlx, window->img_floor, x * 64, y * 64) < 0)
        			error();
			}
			if (window->map[y][x] == 'C')
			{
				if (mlx_image_to_window(window->mlx, window->img_collec, x * 64, y * 64) < 0)
        			error();
			}
			if (window->map[y][x] == 'P')
			{
				if (mlx_image_to_window(window->mlx, window->img_floor, x * 64, y * 64) < 0)
        			error();
				if (mlx_image_to_window(window->mlx, window->img_start, x * 64, y * 64) < 0)
        			error();
			}
			if (window->map[y][x] == 'E')
			{
				if (mlx_image_to_window(window->mlx, window->img_exit, x * 64, y * 64) < 0)
        			error();
			}
			x++;
		}
		y++;
	}
}
	

int32_t	ft_delete(t_data *window)
{
	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(window->mlx, window->img_wall);
	mlx_delete_image(window->mlx, window->img_floor);
	mlx_delete_image(window->mlx, window->img_collec);
	mlx_delete_image(window->mlx, window->img_start);
	mlx_delete_image(window->mlx, window->img_exit);
	mlx_delete_texture(window->texture_wall);
	mlx_delete_texture(window->texture_floor);
	mlx_delete_texture(window->texture_collec);
	mlx_delete_texture(window->texture_start);
	mlx_delete_texture(window->texture_exit);
	mlx_terminate(window->mlx);
	return (EXIT_SUCCESS);
}
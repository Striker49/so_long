/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.>c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:54:07 by seroy             #+#    #+#             */
/*   Updated: 2023/03/28 17:49:58 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// #include "../MLX42/include/MLX42/MLX42.h"


// // Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// // Print the window width and height.
// // static void ft_hook(void* param)
// // {
// // 	const mlx_t* mlx = param;

// // 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// // }

// int32_t	main(void)
// {

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		ft_error();

// 	/* Do stuff */

// 	// Create and display the image.
// 	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_error();

// 	// Even after the image is being displayed, we can still modify the buffer.
// 	mlx_put_pixel(img, 0, 0, 0xFF000000);

// 	// Register a hook and pass mlx as an optional param.
// 	// NOTE: Do this before calling mlx_loop!
// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

// void ft_init_window(t_window *window)
// {
// 	window->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!window->mlx)
// 		puts(mlx_strerror(mlx_errno));
// 	// Convert texture to a displayable image
// 	window->img = mlx_texture_to_image(window->mlx, window->texture);
// // 	if (!window->img)
// }
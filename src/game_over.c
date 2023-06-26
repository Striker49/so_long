/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:34:36 by seroy             #+#    #+#             */
/*   Updated: 2023/06/26 18:45:11 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_game_over(void *param)
{
	t_data	*window;
	char	*go;

	window = param;
	go = "Game over..!";
	window->image.img_game_over2 = mlx_put_string(window->mlx, go, \
	window->w / 2 * 64, window->h / 2 * 64);
}

void	game_over(void *param)
{
	t_data	*window;

	window = param;
	if (window->game_state == 0)
	{
		printf("%s", "Game Over..!");
	}
	window->game_state = 1;
	mlx_delete_image(window->mlx, window->image2.img_game_over2);
	window->image.img_game_over2 = mlx_put_string(window->mlx, "Game Over..!", \
	window->w / 2 * 64, window->h / 2 * 64);
	window->image.img_game_over = \
	mlx_texture_to_image(window->mlx, window->image.texture_game_over);
	window->image.img_game_over2 = window->image.img_game_over2;
	mlx_image_to_window(window->mlx, window->image.img_game_over, 0, 0);
}

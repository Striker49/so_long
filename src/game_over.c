/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:34:36 by seroy             #+#    #+#             */
/*   Updated: 2023/05/31 17:40:26 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    game_over(void *param)
{
	t_data *window;

	window = param;
	if (window->game_state == 0)
		printf("%s", "Game Over..!");
	window->game_state = 1;
    // ft_delete2(window);
	window->image.texture_game_over = mlx_load_png("./temp/game_over.png");
	window->image.img_game_over = mlx_texture_to_image(window->mlx, window->image.texture_game_over);
	// mlx_resize_image(window->image.img_game_over, window->w, window->h);
	// mlx_new_image(window->mlx, window->w, window->h);
    mlx_image_to_window(window->mlx, window->image.img_game_over, 0, 0);

}
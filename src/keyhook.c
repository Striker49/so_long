/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:58:51 by seroy             #+#    #+#             */
/*   Updated: 2023/05/18 18:09:44 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Key Pressed
void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data		*change;

	change = param;

	// If we PRESS the 'up' key, go up.
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W) && keydata.action == MLX_PRESS)
		ft_player_move(1, change);

	// If we PRESS the 'down' key, go down.
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)&& keydata.action == MLX_PRESS)
		ft_player_move(2, change);

	// If we PRESS the 'left' key, go left.
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A) && keydata.action == MLX_PRESS)
		ft_player_move(3, change);

	// If we PRESS the 'right' key, go right.
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D) && keydata.action == MLX_PRESS)
		ft_player_move(4, change);

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
}

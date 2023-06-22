/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:58:51 by seroy             #+#    #+#             */
/*   Updated: 2023/06/22 14:05:24 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Key Pressed
void	my_keyhook(mlx_key_data_t	keydata, void	*param)
{
	t_data	*change;

	change = param;
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W) \
	&& keydata.action == MLX_PRESS)
		ft_player_move(1, change);
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S) \
	&& keydata.action == MLX_PRESS)
		ft_player_move(2, change);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A) \
	&& keydata.action == MLX_PRESS)
		ft_player_move(3, change);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D) \
	&& keydata.action == MLX_PRESS)
		ft_player_move(4, change);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		// ft_delete(change);
		// ft_delete2(change);
		ft_free_all(change);
		exit (0);	
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:56:22 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/18 16:56:31 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_data *data, void *image)
{
	t_coor	coor;

	coor.x = (data->width - END_TILE_WIDTH) / 2;
	coor.y = (data->height - END_TILE_HEIGHT) / 2;
	mlx_put_image_to_window(data->mlx, data->window, image, coor.x, coor.y);
	data->end_game = 1;
	data->end_game_graphic = image;
}

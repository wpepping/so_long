/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:41:53 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/09 19:12:27 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	putimg(t_data *data, void *img, t_coor coor)
{
	mlx_put_image_to_window(data->mlx, data->window, img,
		coor.x * TILE_WIDTH, coor.y * TILE_HEIGHT);
}

static void	draw_tile(t_data *data, t_coor coor)
{
	if (coor.x == data->ppos.x && coor.y == data->ppos.y)
		putimg(data, data->textures.player, data->ppos);
	else if (data->map[coor.y][coor.x] == WALL)
		putimg(data, data->textures.wall[rand() % 3], coor);
	else if (data->map[coor.y][coor.x] == COLLECTIBLE)
		putimg(data, data->textures.weapon1, coor);
	else if (data->map[coor.y][coor.x] == MAPEXIT)
		putimg(data, data->textures.target, coor);
	else
		putimg(data, data->textures.background, coor);
}

void	init_map(t_data *data)
{
	t_coor	coor;

	init_textures(data);
	coor.y = 0;
	while (coor.y < data->map_height)
	{
		coor.x = 0;
		while (coor.x < data->map_width)
		{
			draw_tile(data, coor);
			coor.x++;
		}
		coor.y++;
	}
}

void	move_player(t_data *data, int x, int y)
{
	t_coor	pos_old;

	pos_old.x = data->ppos.x;
	pos_old.y = data->ppos.y;
	if (data->map[data->ppos.y + y][data->ppos.x + x] != WALL)
	{
		data->ppos.x += x;
		data->ppos.y += y;
		if (data->map[data->ppos.y][data->ppos.x] == COLLECTIBLE)
		{
			data->map[data->ppos.y][data->ppos.x] = EMPTY;
			data->collected++;
		}
		if ((data->map[data->ppos.y][data->ppos.x] == MAPEXIT)
			&& data->collected == data->collectibles)
			mlx_loop_end(data->mlx);
	}
	draw_tile(data, pos_old);
	draw_tile(data, data->ppos);
}

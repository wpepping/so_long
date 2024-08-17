/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:41:53 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/17 19:23:56 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_data *data, void *img, t_coor coor)
{
	mlx_put_image_to_window(data->mlx, data->window, img,
		coor.x * TILE_WIDTH, coor.y * TILE_HEIGHT);
}

void	draw_tile(t_data *data, t_coor coor)
{
	if (coor.x == data->enemy.pos.x && coor.y == data->enemy.pos.y)
		put_tile(data, data->textures.enemy, coor);
	else if (coor.x == data->ppos.x && coor.y == data->ppos.y)
	{
		if (data->end_game)
			put_tile(data, data->textures.player_dead, coor);
		else
			put_tile(data, data->textures.player, coor);
	}
	else if (data->map[coor.y][coor.x] == WALL)
		put_tile(data, data->textures.wall[rand() % 3], coor);
	else if (data->map[coor.y][coor.x] == COLLECTIBLE)
		put_tile(data, data->textures.weapon[0], coor);
	else if (data->map[coor.y][coor.x] == MAPEXIT)
		put_tile(data, data->textures.target, coor);
	else
		put_tile(data, data->textures.background, coor);
}

void	draw_bullet(t_data *data, t_bullet *b)
{
	if (b->pospix.x != -1)
		mlx_put_image_to_window(data->mlx, data->window,
			data->textures.bullet, b->pospix.x, b->pospix.y);
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

void	end_game(t_data *data, void *image)
{
	t_coor	coor;

	coor.x = (data->width - END_TILE_WIDTH) / 2;
	coor.y = (data->height - END_TILE_HEIGHT) / 2;
	mlx_put_image_to_window(data->mlx, data->window, image, coor.x, coor.y);
	data->end_game = 1;
	data->end_game_graphic = image;
}

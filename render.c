/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:41:53 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/18 17:05:18 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_data *data, void *img, t_coor coor)
{
	mlx_put_image_to_window(data->mlx, data->window, img,
		coor.x * TILE_WIDTH, coor.y * TILE_HEIGHT);
}

static void	draw_player(t_data *data, t_coor coor)
{
	if (data->end_game)
		put_tile(data, data->textures.player_dead, coor);
	else if (data->pdir.x == -1)
		put_tile(data, data->textures.player_left, coor);
	else if (data->pdir.y == -1)
		put_tile(data, data->textures.player_up, coor);
	else if (data->pdir.y == 1)
		put_tile(data, data->textures.player_down, coor);
	else
		put_tile(data, data->textures.player, coor);
}

void	draw_tile(t_data *data, t_coor coor)
{
	if (coor.x == data->enemy.pos.x && coor.y == data->enemy.pos.y)
		put_tile(data, data->textures.enemy, coor);
	else if (coor.x == data->ppos.x && coor.y == data->ppos.y)
		draw_player(data, coor);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:36:28 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/11 19:18:22 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	random_direction(t_enemy *e)
{
	int	n;

	n = rand() % 4;
	if (n == 0)
	{
		e->dir_x = 1;
		e->dir_y = 0;
	}
	if (n == 1)
	{
		e->dir_x = -1;
		e->dir_y = 0;
	}
	if (n == 2)
	{
		e->dir_x = 0;
		e->dir_y = 1;
	}
	if (n == 3)
	{
		e->dir_x = 0;
		e->dir_y = -1;
	}
}

int	update_enemy(t_data *data)
{
	t_enemy	*e;
	t_coor	pos_old;

	e = &data->enemy;
	if (!data->end_game && currtime() - e->movetime >= 500)
	{
		while (data->map[e->dir_y + e->pos.y][e->dir_x + e->pos.x] == WALL)
			random_direction(e);
		pos_old.x = e->pos.x;
		pos_old.y = e->pos.y;
		e->pos.x += e->dir_x;
		e->pos.y += e->dir_y;
		e->movetime = currtime();
		draw_tile(data, pos_old);
		draw_tile(data, e->pos);
		if (data->ppos.x == e->pos.x && data->ppos.y == e->pos.y)
			end_game(data, data->textures.wasted);
	}
	return (0);
}

void	move_player(t_data *d, int x, int y)
{
	t_coor	pos_old;

	if (d->end_game || d->map[d->ppos.y + y][d->ppos.x + x] == WALL)
		return ;
	pos_old.x = d->ppos.x;
	pos_old.y = d->ppos.y;
	d->ppos.x += x;
	d->ppos.y += y;
	if (d->map[d->ppos.y][d->ppos.x] == COLLECTIBLE)
	{
		d->map[d->ppos.y][d->ppos.x] = EMPTY;
		d->collected++;
	}
	if (d->ppos.x == d->enemy.pos.x && d->ppos.y == d->enemy.pos.y)
		end_game(d, d->textures.wasted);
	else if ((d->map[d->ppos.y][d->ppos.x] == MAPEXIT)
		&& d->collected == d->collectibles)
		end_game(d, d->textures.youwin);
	else
	{
		draw_tile(d, pos_old);
		draw_tile(d, d->ppos);
	}
}

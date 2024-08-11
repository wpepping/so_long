/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:36:28 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/11 18:36:06 by wpepping         ###   ########.fr       */
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

int	update_enemy(t_data *d)
{
	t_enemy	*e;
	t_coor	pos_old;

	e = &d->enemy;
	if (currtime() - e->movetime >= 500)
	{
		while (d->map[e->dir_y + e->pos.y][e->dir_x + e->pos.x] == WALL)
			random_direction(e);
		pos_old.x = e->pos.x;
		pos_old.y = e->pos.y;
		e->pos.x += e->dir_x;
		e->pos.y += e->dir_y;
		e->movetime = currtime();
		draw_tile(d, pos_old);
		draw_tile(d, e->pos);
		if (d->ppos.x == e->pos.x && d->ppos.y == e->pos.y)
			wasted(d);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:36:28 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/17 18:32:19 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_turn(t_data *d)
{
	t_enemy	*e;

	e = &d->enemy;
	if (e->dir.x)
	{
		if (d->map[e->pos.y + 1][e->pos.x] != WALL ||
			d->map[e->pos.y - 1][e->pos.x] != WALL)
			return (1);
		return (0);
	}
	if (d->map[e->pos.y][e->pos.x + 1] != WALL ||
		d->map[e->pos.y][e->pos.x - 1] != WALL)
		return (1);
	return (0);
}

static void	random_direction(t_data *d, t_coor *dir_new)
{
	int		n;
	t_enemy	*e;

	e = &d->enemy;
	if (can_turn(d))
	{
		n = rand() % 2;
		if (e->dir.x)
			n += 2;
	}
	else
		n = rand() % 4;
	if (n == 0 || n == 1)
		dir_new->y = 0;
	else
		dir_new->x = 0;
	if (n == 0)
		dir_new->x = 1;
	else if (n == 1)
		dir_new->x = -1;
	else if (n == 2)
		dir_new->y = 1;
	else if (n == 3)
		dir_new->y = -1;
}

int	update_enemy(t_data *d, t_enemy	*e)
{
	t_coor	pos_old;
	t_coor	dir_new;

	copy_coor(&dir_new, &e->dir);
	if (currtime() - e->movetime >= 500)
	{
		if (rand() % 4 == 0 && can_turn(d))
			random_direction(d, &dir_new);
		while (d->map[e->pos.y + dir_new.y][e->pos.x + dir_new.x] == WALL)
			random_direction(d, &dir_new);
		copy_coor(&e->dir, &dir_new);
		copy_coor(&pos_old, &e->pos);
		e->pos.x += e->dir.x;
		e->pos.y += e->dir.y;
		e->movetime = currtime();
		draw_tile(d, pos_old);
		draw_tile(d, e->pos);
		if (d->end_game)
			end_game(d, d->end_game_graphic);
		else if ((d->ppos.x == e->pos.x && d->ppos.y == e->pos.y))
			end_game(d, d->textures.wasted);
	}
	return (0);
}

void	move_player(t_data *d, int x, int y)
{
	t_coor	pos_old;

	copy_coor(&d->pdir, &(t_coor){x, y});
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
	draw_tile(d, pos_old);
	draw_tile(d, d->ppos);
	if (d->ppos.x == d->enemy.pos.x && d->ppos.y == d->enemy.pos.y)
		end_game(d, d->textures.wasted);
	else if ((d->map[d->ppos.y][d->ppos.x] == MAPEXIT)
		&& d->collected == d->collectibles)
		end_game(d, d->textures.youwin);
}

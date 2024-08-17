/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:32:27 by wouter            #+#    #+#             */
/*   Updated: 2024/08/17 19:29:59 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shoot(t_data *data, t_bullet *bullet)
{
	if (data->collected)
	{
		copy_coor(&data->bullet.dir, &data->pdir);
		data->bullet.pospix.x = (data->ppos.x + 1) * TILE_WIDTH;
		if (data->bullet.dir.x == -1)
			data->bullet.pospix.x -= TILE_WIDTH;
		else if (data->bullet.dir.x == 0)
			data->bullet.pospix.x -= TILE_WIDTH / 2 + BULLET_SIZE / 2;
		data->bullet.pospix.y = (data->ppos.y + 1) * TILE_HEIGHT;
		if (data->bullet.dir.y == -1)
			data->bullet.pospix.y -= TILE_HEIGHT;
		else if (data->bullet.dir.y == 0)
			data->bullet.pospix.y -= TILE_HEIGHT / 2 + BULLET_SIZE / 2;
		data->bullet.postile.x = data->bullet.pospix.x / 64;
		data->bullet.postile.y = data->bullet.pospix.y / 64;
		data->bullet.movetime = currtime();
	}
}

void	kill_enemy(t_data *d, t_enemy *e, t_bullet *b)
{
	t_coor	enemy_tile;

	copy_coor(&enemy_tile, &d->enemy.pos);
	copy_coor(&d->enemy.pos, &(t_coor){-1, -1});
	copy_coor(&d->bullet.pospix, &(t_coor){-1, -1});
	draw_tile(d, enemy_tile);
}

int	update_bullet(t_data *d, t_bullet *b)
{
	t_coor	old_tile;

	if (currtime() - b->movetime >= 3)
	{
		old_tile.x = d->bullet.pospix.x / 64;
		old_tile.y = d->bullet.pospix.y / 64;
		d->bullet.pospix.x += d->bullet.dir.x * BULLET_SIZE;
		d->bullet.pospix.y += d->bullet.dir.y * BULLET_SIZE;
		d->bullet.postile.x = d->bullet.pospix.x / 64;
		d->bullet.postile.y = d->bullet.pospix.y / 64;
		if (d->map[b->postile.y][b->postile.x] == WALL)
			copy_coor(&d->bullet.pospix, &(t_coor){-1, -1});
		if (b->postile.x == d->enemy.pos.x && b->postile.y == d->enemy.pos.y)
			kill_enemy(d, &d->enemy, &d->bullet);
		if (old_tile.x != b->postile.x || old_tile.y != b->postile.y)
			draw_tile(d, old_tile);
		draw_bullet(d, b);
		b->movetime = currtime();
	}
}

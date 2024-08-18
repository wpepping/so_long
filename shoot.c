/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:32:27 by wouter            #+#    #+#             */
/*   Updated: 2024/08/18 15:17:58 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shoot(t_data *data, t_bullet *bullet)
{
	if (data->collected)
	{
		copy_coor(&bullet->dir, &data->pdir);
		bullet->pospix.x = (data->ppos.x + 1) * TILE_WIDTH;
		if (bullet->dir.x == -1)
			bullet->pospix.x -= TILE_WIDTH;
		else if (bullet->dir.x == 0)
			bullet->pospix.x -= TILE_WIDTH / 2 + BULLET_SIZE / 2;
		bullet->pospix.y = (data->ppos.y + 1) * TILE_HEIGHT;
		if (bullet->dir.y == -1)
			bullet->pospix.y -= TILE_HEIGHT;
		else if (bullet->dir.y == 0)
			bullet->pospix.y -= TILE_HEIGHT / 2 + BULLET_SIZE / 2;
		bullet->postile.x = bullet->pospix.x / 64;
		bullet->postile.y = bullet->pospix.y / 64;
		bullet->movetime = currtime();
	}
}

void	kill_enemy(t_data *d, t_enemy *e, t_bullet *b)
{
	t_coor	enemy_tile;

	copy_coor(&enemy_tile, &e->pos);
	copy_coor(&e->pos, &(t_coor){-1, -1});
	copy_coor(&b->pospix, &(t_coor){-1, -1});
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
	return (0);
}

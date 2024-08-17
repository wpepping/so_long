/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:01:31 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/17 18:32:46 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_loop(t_data *data)
{
	if (data->enemy.pos.x > -1)
		update_enemy(data, &data->enemy);
	if (data->bullet.pospix.x > -1)
		update_bullet(data, &data->bullet);
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	handle_input(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx);
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		move_player(data, 0, -1);
	if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		move_player(data, 0, 1);
	if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		move_player(data, -1, 0);
	if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		move_player(data, 1, 0);
	if (keycode == XK_space)
		shoot(data, &data->bullet);
	return (0);
}

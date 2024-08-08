/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:01:31 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/08 15:44:42 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_loop(void)
{
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
	if (keycode == XK_w || keycode == XK_W)
		move_player(data, 0, -1);
	if (keycode == XK_s || keycode == XK_S)
		move_player(data, 0, 1);
	if (keycode == XK_a || keycode == XK_A)
		move_player(data, -1, 0);
	if (keycode == XK_d || keycode == XK_D)
		move_player(data, 1, 0);
	return (0);
}

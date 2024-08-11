/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:12:34 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/11 19:05:45 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_more_textures(t_data *data)
{

	data->textures.wall[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/rock1.xpm", &data->dummy, &data->dummy);
	data->textures.wall[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/rock2.xpm", &data->dummy, &data->dummy);
	data->textures.wall[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/rock3.xpm", &data->dummy, &data->dummy);
	data->textures.weapon1 = mlx_xpm_file_to_image(data->mlx,
			"textures/weaponR1.xpm", &data->dummy, &data->dummy);
	data->textures.weapon2 = mlx_xpm_file_to_image(data->mlx,
			"textures/weaponR2.xpm", &data->dummy, &data->dummy);
	data->textures.weapon3 = mlx_xpm_file_to_image(data->mlx,
			"textures/weaponR3.xpm", &data->dummy, &data->dummy);
}

void	init_textures(t_data *data)
{
	data->textures.background = mlx_xpm_file_to_image(data->mlx,
			"textures/background.xpm", &data->dummy, &data->dummy);
	data->textures.player = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &data->dummy, &data->dummy);
	data->textures.player_dead = mlx_xpm_file_to_image(data->mlx,
			"textures/player_dead.xpm", &data->dummy, &data->dummy);
	data->textures.target = mlx_xpm_file_to_image(data->mlx,
			"textures/crosshair_small.xpm", &data->dummy, &data->dummy);
	data->textures.enemy = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy.xpm", &data->dummy, &data->dummy);
	data->textures.wasted = mlx_xpm_file_to_image(data->mlx,
			"textures/wasted.xpm", &data->dummy, &data->dummy);
	data->textures.youwin = mlx_xpm_file_to_image(data->mlx,
			"textures/youwin.xpm", &data->dummy, &data->dummy);
	init_more_textures(data);
}

void	clear_textures(t_data *data)
{
	mlx_destroy_image(data->mlx, data->textures.background);
	mlx_destroy_image(data->mlx, data->textures.player);
	mlx_destroy_image(data->mlx, data->textures.player_dead);
	mlx_destroy_image(data->mlx, data->textures.wall[0]);
	mlx_destroy_image(data->mlx, data->textures.wall[1]);
	mlx_destroy_image(data->mlx, data->textures.wall[2]);
	mlx_destroy_image(data->mlx, data->textures.weapon1);
	mlx_destroy_image(data->mlx, data->textures.weapon2);
	mlx_destroy_image(data->mlx, data->textures.weapon3);
	mlx_destroy_image(data->mlx, data->textures.target);
	mlx_destroy_image(data->mlx, data->textures.enemy);
	mlx_destroy_image(data->mlx, data->textures.wasted);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:12:34 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/18 17:01:02 by wpepping         ###   ########.fr       */
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
	data->textures.weapon[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/weaponR1.xpm", &data->dummy, &data->dummy);
	data->textures.weapon[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/weaponR2.xpm", &data->dummy, &data->dummy);
	data->textures.weapon[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/weaponR3.xpm", &data->dummy, &data->dummy);
	data->textures.target = mlx_xpm_file_to_image(data->mlx,
			"textures/crosshair_small.xpm", &data->dummy, &data->dummy);
	data->textures.bullet = mlx_xpm_file_to_image(data->mlx,
			"textures/bullet.xpm", &data->dummy, &data->dummy);
}

void	init_textures(t_data *data)
{
	data->textures.background = mlx_xpm_file_to_image(data->mlx,
			"textures/background.xpm", &data->dummy, &data->dummy);
	data->textures.player = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &data->dummy, &data->dummy);
	data->textures.player_left = mlx_xpm_file_to_image(data->mlx,
			"textures/player_left.xpm", &data->dummy, &data->dummy);
	data->textures.player_up = mlx_xpm_file_to_image(data->mlx,
			"textures/player_up.xpm", &data->dummy, &data->dummy);
	data->textures.player_down = mlx_xpm_file_to_image(data->mlx,
			"textures/player_down.xpm", &data->dummy, &data->dummy);
	data->textures.player_dead = mlx_xpm_file_to_image(data->mlx,
			"textures/player_dead.xpm", &data->dummy, &data->dummy);
	data->textures.enemy = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy.xpm", &data->dummy, &data->dummy);
	data->textures.enemy_dead = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy_dead.xpm", &data->dummy, &data->dummy);
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
	mlx_destroy_image(data->mlx, data->textures.player_left);
	mlx_destroy_image(data->mlx, data->textures.player_up);
	mlx_destroy_image(data->mlx, data->textures.player_down);
	mlx_destroy_image(data->mlx, data->textures.player_dead);
	mlx_destroy_image(data->mlx, data->textures.wall[0]);
	mlx_destroy_image(data->mlx, data->textures.wall[1]);
	mlx_destroy_image(data->mlx, data->textures.wall[2]);
	mlx_destroy_image(data->mlx, data->textures.weapon[0]);
	mlx_destroy_image(data->mlx, data->textures.weapon[1]);
	mlx_destroy_image(data->mlx, data->textures.weapon[2]);
	mlx_destroy_image(data->mlx, data->textures.target);
	mlx_destroy_image(data->mlx, data->textures.enemy);
	mlx_destroy_image(data->mlx, data->textures.enemy_dead);
	mlx_destroy_image(data->mlx, data->textures.wasted);
	mlx_destroy_image(data->mlx, data->textures.youwin);
	mlx_destroy_image(data->mlx, data->textures.bullet);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:12:34 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/09 19:14:53 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_data *data)
{
	int	i;

	data->textures.background = mlx_xpm_file_to_image(data->mlx,
			"textures/background.xpm", &i, &i);
	data->textures.player = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &i, &i);
	data->textures.wall[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/rock1.xpm", &i, &i);
	data->textures.wall[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/rock2.xpm", &i, &i);
	data->textures.wall[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/rock3.xpm", &i, &i);
	data->textures.weapon1 = mlx_xpm_file_to_image(data->mlx,
			"textures/weaponR1.xpm", &i, &i);
	data->textures.weapon2 = mlx_xpm_file_to_image(data->mlx,
			"textures/weaponR2.xpm", &i, &i);
	data->textures.weapon3 = mlx_xpm_file_to_image(data->mlx,
			"textures/weaponR3.xpm", &i, &i);
	data->textures.target = mlx_xpm_file_to_image(data->mlx,
			"textures/crosshair_small.xpm", &i, &i);
}

void	clear_textures(t_data *data)
{
	mlx_destroy_image(data->mlx, data->textures.background);
	mlx_destroy_image(data->mlx, data->textures.player);
	mlx_destroy_image(data->mlx, data->textures.wall[0]);
	mlx_destroy_image(data->mlx, data->textures.wall[1]);
	mlx_destroy_image(data->mlx, data->textures.wall[2]);
	mlx_destroy_image(data->mlx, data->textures.weapon1);
	mlx_destroy_image(data->mlx, data->textures.weapon2);
	mlx_destroy_image(data->mlx, data->textures.weapon3);
	mlx_destroy_image(data->mlx, data->textures.target);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:37:42 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/08 17:54:29 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	err_handl(char *msg, t_data *data)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (data->mlx != NULL)
	{
		if (data->window != NULL)
			mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(data->map);
	return (1);
}

static int	init(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->mlx = mlx_init();
	data->width = TILE_WIDTH * data->map_width;
	data->height = TILE_HEIGHT * data->map_height;
	data->collected = 0;
	data->collectibles = 0;
	if (data->mlx == NULL)
		return (-1);
	data->window = mlx_new_window(data->mlx, data->width, data->height,
			"And thanks for all the fish.");
	if (data->window == NULL)
		return (err_handl("Error creating window", data));
	return (0);
}

static void	init_events(t_data *data)
{
	mlx_key_hook(data->window, &handle_input, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask,
		&handle_close, data);
}

static int	check_input(t_data *data, int argc, char *argv[])
{
	data->map = NULL;
	if (argc != 2)
		return (err_handl("Usage: so_long <map name>", data));
	if (read_map(data, argv[1]) < 0)
		return (err_handl("Map error", data));
	if (check_ppos_and_exit(data) < 0)
		return (err_handl("Map error", data));
	if (!is_valid_map(data))
		return (err_handl("Map error", data));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_input(&data, argc, argv))
		return (1);
	if (init(&data) < 0)
		return (1);
	init_map(&data);
	init_events(&data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.window);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	free_map(data.map);
	return (0);
}

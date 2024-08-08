/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:40:06 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/08 17:53:21 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	chk_tile(t_data *data, int x, int y, char **is_checked)
{
	int	result;

	if (is_checked[y][x] == 1)
		return (0);
	if (data->map[y][x] == WALL)
		return (0);
	if (x == 0 || x == data->map_width - 1
		|| y == 0 || y == data->map_height - 1)
		return (-1);
	result = 0;
	if (data->map[y][x] == COLLECTIBLE)
		result++;
	is_checked[y][x] = 1;
	return (
		result
		+ chk_tile(data, x + 1, y, is_checked)
		+ chk_tile(data, x - 1, y, is_checked)
		+ chk_tile(data, x, y + 1, is_checked)
		+ chk_tile(data, x, y - 1, is_checked)
	);
}

int	is_valid_map(t_data *data)
{
	char	**is_checked;
	int		i;

	is_checked = ft_calloc(data->map_height + 1, sizeof(char *));
	i = 0;
	while (i < data->map_height)
		is_checked[i++] = ft_calloc(data->map_width, sizeof(char));
	i = chk_tile(data, data->ppos.x, data->ppos.y, is_checked);
	free_map(is_checked);
	if (i != data->collectibles)
		return (0);
	return (1);
}

int	check_ppos_and_exit(t_data *data)
{
	t_coor	coor;
	int		exits;
	int		pstarts;

	coor.y = -1;
	exits = 0;
	pstarts = 0;
	while (++(coor.y) < data->map_height)
	{
		coor.x = -1;
		while (++(coor.x) < data->map_width)
		{
			if (data->map[coor.y][coor.x] == PSTART)
			{
				pstarts++;
				data->ppos.x = coor.x;
				data->ppos.y = coor.y;
			}
			else if (data->map[coor.y][coor.x] == MAPEXIT)
				exits++;
		}
	}
	if (pstarts != 1 || exits != 1)
		return (-1);
	return (0);
}

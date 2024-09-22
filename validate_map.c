/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:40:06 by wpepping          #+#    #+#             */
/*   Updated: 2024/09/22 11:45:13 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_tile(t_data *data, int x, int y, char **is_checked)
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
	if (data->map[y][x] == COLLECTIBLE || data->map[y][x] == MAPEXIT)
		result++;
	is_checked[y][x] = 1;
	return (
		result
		+ check_tile(data, x + 1, y, is_checked)
		+ check_tile(data, x - 1, y, is_checked)
		+ check_tile(data, x, y + 1, is_checked)
		+ check_tile(data, x, y - 1, is_checked)
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
	i = check_tile(data, data->ppos.x, data->ppos.y, is_checked);
	free_map(is_checked);
	if (i != data->collectibles + 1)
		return (0);
	return (1);
}

static void	check_special_tile(t_data *data, t_coor *coor, t_tilecount *tc)
{
	if (data->map[coor->y][coor->x] == PSTART)
	{
		(tc->pstarts)++;
		data->ppos.x = coor->x;
		data->ppos.y = coor->y;
	}
	if (data->map[coor->y][coor->x] == ESTART)
	{
		(tc->estarts)++;
		data->enemy.pos.x = coor->x;
		data->enemy.pos.y = coor->y;
	}
	else if (data->map[coor->y][coor->x] == MAPEXIT)
		(tc->exits)++;
	else if (data->map[coor->y][coor->x] == COLLECTIBLE)
		data->collectibles++;
}

int	check_special_tiles(t_data *data)
{
	t_coor		coor;
	t_tilecount	tc;

	coor.y = -1;
	tc.exits = 0;
	tc.pstarts = 0;
	tc.estarts = 0;
	while (++(coor.y) < data->map_height)
	{
		coor.x = -1;
		while (++(coor.x) < data->map_width)
			check_special_tile(data, &coor, &tc);
	}
	if (tc.pstarts != 1 || tc.exits != 1 || tc.estarts > 1)
		return (-1);
	return (0);
}

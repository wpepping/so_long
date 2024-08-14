/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:09:24 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/14 18:33:25 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

long	currtime(void)
{
	struct timeval	result;

	if (gettimeofday(&result, NULL))
		ft_putendl_fd("Error getting current time.", STDOUT_FILENO);
	return (result.tv_sec * 1000 + result.tv_usec / 1000);
}

void	copy_coor(t_coor *c1, t_coor *c2)
{
	c1->x = c2->x;
	c1->y = c2->y;
}

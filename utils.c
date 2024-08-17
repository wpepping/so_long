/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:09:24 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/17 18:53:31 by wouter           ###   ########.fr       */
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*p;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	p = dest;
	while (i < n)
	{
		*(p + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

void	get_color(t_data *data, int c[3], char *result)
{
	int	color;

	color = (c[0] * 256 * 256 + c[1] * 256 + c[2]);
	color = mlx_get_color_value(data->mlx, color);
	ft_memcpy(result, &color, 4);
}

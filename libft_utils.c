/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:40:03 by wpepping          #+#    #+#             */
/*   Updated: 2024/08/05 16:51:25 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		*((unsigned char *)s + i++) = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	int		memsize;

	memsize = nmemb * size;
	if (nmemb != 0 && memsize / nmemb != size)
		return (NULL);
	result = malloc(memsize);
	if (result != NULL)
		ft_memset(result, '\0', memsize);
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i++] != '\0')
		;
	return (i - 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

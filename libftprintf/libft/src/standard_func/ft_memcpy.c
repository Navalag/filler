/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:33:47 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/03 11:33:50 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dst. If dst and src overlap, behavior is undefined. Applications in which
** dst and src might overlap should use memmove(3) instead.
**
** Return values: The ft_memcpy() function returns the original value of dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

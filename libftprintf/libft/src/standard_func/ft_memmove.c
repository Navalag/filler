/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:47:39 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/03 16:47:42 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The ft_memmove() function copies len bytes from string src to string dst. The
** two strings may overlap; the copy is always done in a non-destructive man-
** ner.
**
** The ft_memmove() function returns the original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (src < dst)
	{
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	else
	{
		while (++i < len)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}

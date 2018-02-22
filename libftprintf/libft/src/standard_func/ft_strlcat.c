/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 10:40:41 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/02 10:40:43 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** The strlcat() function copy and concatenate strings respec-
** tively. They are designed to be safer, more consistent, and less error
** prone replacements for strncpy(3) and strncat(3). Unlike those functions,
** strlcat() take the full size of the buffer (not just the
** length) and guarantee to NUL-terminate the result (as long as size is
** larger than 0 or, in the case of strlcat(), as long as there is at least
** one byte free in dst). Note that a byte for the NUL should be included in
** size. Also note that strlcat() only operate on true ``C''
** strings. This means that for strlcat() both src and dst must be
** NUL-terminated.
**
** The strlcat() function appends the NUL-terminated string src to the end of
** dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
** the result.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** The strlcat() function return the total length of the string
** they tried to create. For strlcat() that means the initial length of dst
** plus the length of src.
** While this may seem somewhat confusing, it was done to make truncation
** detection simple.
**
** Note however, that if strlcat() traverses size characters without finding a
** NUL, the length of the string is considered to be size and the destination
** string will not be NUL-terminated (since there was no space for the NUL).
** This keeps strlcat() from running off the end of a string.  In practice
** this should not happen (as it means that either size is incorrect or that
** dst is not a proper ``C'' string). The check exists to prevent potential
** security problems in incorrect code.
*/

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] != '\0' && dst_len < dstsize - 1)
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
		src_len--;
	}
	dst[dst_len] = '\0';
	return (dst_len + src_len);
}

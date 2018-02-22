/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:52:56 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/03 17:52:58 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The ft_memchr() function locates the first occurrence of c (converted to an
** unsigned char) in string s.
**
** The ft_memchr() function returns a pointer to the byte located, or NULL
** if no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

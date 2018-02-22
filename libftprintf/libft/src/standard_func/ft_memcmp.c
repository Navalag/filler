/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:09:34 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/13 10:08:12 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The ft_memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
**
** The memcmp() function returns zero if the two strings are identical, other-
** wise returns the difference between the first two differing bytes (treated
** as unsigned char values, so that `\200' is greater than `\0', for example).
** Zero-length strings are always identical.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

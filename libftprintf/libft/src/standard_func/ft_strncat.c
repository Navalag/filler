/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:03:49 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/01 17:03:52 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The strncat() function append a copy of the null-terminated
** string s2 to the end of the null-terminated string s1, then add a terminat-
** ing `\0'. The string s1 must have sufficient space to hold the result.
**
** The strncat() function appends not more than n characters from s2, and then
** adds a terminating `\0'.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** The strcat() function return the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0' && j < n)
	{
		s1[j + i] = s2[j];
		j++;
	}
	s1[j + i] = '\0';
	return (s1);
}

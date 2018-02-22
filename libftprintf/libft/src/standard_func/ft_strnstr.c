/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:30:31 by agalavan          #+#    #+#             */
/*   Updated: 2017/10/31 16:30:34 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The strnstr() function locates the first occurrence of the null-terminated
** string find in the string array, where not more than l characters are
** searched. Characters that appear after a `\0' character are not searched.
** Since the strnstr() function is a FreeBSD specific API, it should only be
** used when portability is not a concern.
**
** If find is an empty string, array is returned; if find occurs nowhere in
** array, NULL is returned; otherwise a pointer to the first character of the
** first occurrence of find is returned.
*/

char	*ft_strnstr(const char *array, const char *find, size_t l)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (array[j] != '\0' && j < l)
	{
		i = 0;
		while (array[i + j] == find[i] &&
			array[i + j] != '\0' &&
			find[i] != '\0' && (i + j) < l)
			i++;
		if (find[i] == '\0')
			return ((char*)&array[j]);
		j++;
	}
	return (0);
}

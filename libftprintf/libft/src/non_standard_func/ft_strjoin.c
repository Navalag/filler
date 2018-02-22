/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:17:22 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/10 10:17:26 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

/*
** Description: Allocates (with malloc(3)) and returns a “fresh” string ending
** with ’\0’, result of the concatenation of s1 and s2. If
** the allocation fails the function returns NULL.
**
** Param. #1 The prefix string.
** Param. #2 The suffix string.
**
** Return value: The “fresh” string result of the concatenation of the 2
** strings.
** Libc functions: malloc(3)
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	size_t	j;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len_1 + len_2) + 1);
	if (res == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[++j] != '\0')
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

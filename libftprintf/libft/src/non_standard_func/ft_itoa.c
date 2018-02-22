/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:38:39 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/13 10:23:47 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

/*
** Description: Allocate (with malloc(3)) and returns a “fresh” string ending
** with ’\0’ representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
**
** Param. #1 The integer to be transformed into a string.
**
** Return value: The string representing the integer passed as argument.
** Libc functions: malloc(3)
*/

char	*ft_itoa(intmax_t nb)
{
	char		*res;
	uintmax_t	nb_copy;
	size_t		len;

	nb_copy = (nb < 0) ? -nb : nb;
	len = ft_intlen_u(nb_copy, 10);
	if (nb < 0)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb_copy == 0)
		res[0] = '0';
	if (nb < 0)
		res[0] = '-';
	res[len] = '\0';
	while (nb_copy)
	{
		res[--len] = (nb_copy % 10) + '0';
		nb_copy /= 10;
	}
	return (res);
}

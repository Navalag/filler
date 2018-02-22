/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:41:18 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/09 11:41:20 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending
** with ’\0’. Each character of the string is initialized at
** ’\0’. If the allocation fails the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	res = ft_memset(res, '\0', size + 1);
	return (res);
}

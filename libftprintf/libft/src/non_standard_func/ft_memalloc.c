/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:14:24 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/09 09:14:26 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

/*
** Allocates (with malloc(3)) and returns a “fresh” memory
** area. The memory allocated is initialized to 0. If the allocation
** fails, the function returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	res = ft_memset(res, 0, size);
	return (res);
}

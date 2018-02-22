/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:37:57 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/09 10:37:59 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

/*
** Takes as a parameter the address of a memory area that needs
** to be freed with free(3), then puts the pointer to NULL.
*/

void	ft_memdel(void **ap)
{
	if (ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}

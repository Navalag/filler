/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:15:08 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/02 17:15:16 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** The ft_bzero() function writes n zeroed bytes to the string s.  If n is zero,
** bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	char *tmp;

	tmp = s;
	while (n != 0)
	{
		*tmp++ = 0;
		n--;
	}
}

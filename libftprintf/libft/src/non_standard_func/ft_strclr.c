/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:11:47 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/09 12:11:49 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** Sets every character of the string to the value ’\0’.
*/

void	ft_strclr(char *s)
{
	size_t len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	ft_memset(s, '\0', len + 1);
}

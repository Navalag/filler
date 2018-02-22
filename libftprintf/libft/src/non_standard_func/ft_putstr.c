/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:48:22 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/07 19:48:24 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../inc/libft.h"

void	ft_putstr(char const *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (s == NULL)
		return ;
	write(1, s, len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:41:46 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/12 15:41:49 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

char	*ft_itoa_base_u(size_t nb, int base, int up_case)
{
	char	*res;
	int		len;
	char	*symb_lower;
	char	*symb_upper;

	len = ft_intlen_u(nb, base);
	symb_lower = "0123456789abcdef";
	symb_upper = "0123456789ABCDEF";
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (len--)
	{
		res[len] = (up_case) ? symb_upper[nb % base] : symb_lower[nb % base];
		nb /= base;
	}
	return (res);
}

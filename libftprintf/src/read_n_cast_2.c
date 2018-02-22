/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_cast_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:35:49 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/14 10:35:52 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*cast_s_size(va_list ap)
{
	char	*res;

	res = va_arg(ap, char *);
	if (res == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(res);
	return (res);
}

wchar_t	*cast_utf_s_size(va_list ap)
{
	return (va_arg(ap, wchar_t *));
}

char	cast_c_size(va_list ap)
{
	return ((unsigned char)va_arg(ap, int));
}

wchar_t	cast_utf_c_size(va_list ap)
{
	return (va_arg(ap, wchar_t));
}

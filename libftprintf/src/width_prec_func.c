/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:18:31 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/11 16:18:35 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*set_int_precision(char *res)
{
	char	*res_prec;
	int		diff;

	if (g_printf->width < g_printf->precision)
	{
		free(res);
		res_prec = (char *)malloc(g_printf->precision + 1);
		res_prec = ft_memset(res_prec, '0', g_printf->precision);
		res_prec[g_printf->precision] = '\0';
		return (res_prec);
	}
	else
	{
		diff = g_printf->width - g_printf->precision;
		ft_memset(res + diff, '0', g_printf->precision);
	}
	return (res);
}

char	*set_width(int prec_y_n)
{
	char	*res;

	res = (char *)malloc(g_printf->width + 1);
	res = ft_memset(res, ' ', g_printf->width);
	res[g_printf->width] = '\0';
	return ((prec_y_n) ? set_int_precision(res) : res);
}

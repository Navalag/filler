/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:04:05 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/11 11:04:07 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_printf(char *frm, ...)
{
	va_list		ap;
	int			ret_value;
	int			count;

	va_start(ap, frm);
	ret_value = 0;
	while (*frm)
	{
		if (*frm != '%')
		{
			ft_putchar(*frm);
			ret_value++;
		}
		else if (*++frm)
		{
			count = read_flags_from_format(frm);
			frm += count;
			ret_value += continue_with_conversions(frm, ap);
		}
		if (*frm)
			frm++;
	}
	va_end(ap);
	return (ret_value);
}

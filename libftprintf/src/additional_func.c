/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aditional_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:24:09 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/14 10:24:10 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	clean_flags_struct(void)
{
	g_printf->flag_hesh = 0;
	g_printf->flag_minus = 0;
	g_printf->flag_plus = 0;
	g_printf->flag_zero = 0;
	g_printf->flag_space = 0;
	g_printf->width = 0;
	g_printf->precision = 0;
	g_printf->precision_flag = 0;
	g_printf->size_hh = 0;
	g_printf->size_h = 0;
	g_printf->size_ll = 0;
	g_printf->size_l = 0;
	g_printf->size_j = 0;
	g_printf->size_z = 0;
	g_printf->conver_letter = 0;
}

int		ft_utf_charlen(wchar_t value)
{
	if (value <= 0x7F)
		return (1);
	else if (value <= 0x7FF)
		return (2);
	else if (value <= 0xE08080)
		return (3);
	else
		return (4);
}

int		ft_utf_strlen(wchar_t *value)
{
	int		len;

	len = 0;
	while (*value)
	{
		if (*value <= 0x7F)
			len++;
		else if (*value <= 0x7FF)
			len += 2;
		else if (*value <= 0xE08080)
			len += 3;
		else
			len += 4;
		value++;
	}
	return (len);
}

void	clean_memory_leaks(char *res)
{
	free(g_printf);
	free(res);
}

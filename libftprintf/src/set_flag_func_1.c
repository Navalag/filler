/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag_func1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:00:49 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/14 11:00:51 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*set_flag_for_d_i_u(char *res)
{
	if (g_printf->conver_letter == 'u' || g_printf->conver_letter == 'U')
	{
		g_printf->flag_plus = 0;
		g_printf->flag_space = 0;
	}
	if (g_printf->flag_plus == 1)
		res = set_plus_flag(res);
	else if (g_printf->flag_space == 1)
		res = set_space_flag(res);
	if (g_printf->width > 0)
	{
		if (g_printf->flag_minus == 1)
		{
			res = set_minus_flag(res);
			g_printf->flag_zero = 0;
		}
		else if (g_printf->flag_zero == 1 && g_printf->precision_flag == 0)
			res = set_zero_flag(res);
	}
	return (res);
}

char	*set_flag_for_o_x_p(char *res)
{
	if (g_printf->conver_letter == 'u' || g_printf->conver_letter == 'U')
		return (set_flag_for_d_i_u(res));
	if (g_printf->width > 0)
	{
		if (g_printf->flag_zero == 1 && g_printf->precision_flag == 0
			&& g_printf->flag_minus == 0)
			res = set_zero_flag(res);
		else
			g_printf->flag_zero = 0;
	}
	if (g_printf->flag_hesh == 1 && (g_printf->conver_letter == 'o' ||
		g_printf->conver_letter == 'O'))
		res = set_hesh_flag_for_octal(res);
	else if (g_printf->flag_hesh == 1 || g_printf->conver_letter == 'p')
		res = set_hesh_flag_for_hexadecimal(res);
	if (g_printf->flag_minus == 1)
		res = set_minus_flag(res);
	return (res);
}

char	*set_flag_for_s(char *res)
{
	g_printf->flag_space = 0;
	if (g_printf->width > 0)
	{
		if (g_printf->flag_minus == 1)
			res = set_minus_flag(res);
		else if (g_printf->flag_zero == 1)
			res = set_zero_flag_for_s(res);
	}
	return (res);
}

int		set_flag_for_c(char *width, char value, int width_len, int i)
{
	if (width_len <= 1)
	{
		ft_putchar(value);
		return (1);
	}
	else
	{
		if (g_printf->flag_minus == 1)
		{
			ft_putchar(value);
			ft_putstr(width + 1);
		}
		else if (g_printf->flag_zero == 1)
		{
			while (width_len - 1 > i++)
				ft_putchar('0');
			ft_putchar(value);
		}
		else
		{
			ft_putstr(width + 1);
			ft_putchar(value);
		}
	}
	return (width_len);
}

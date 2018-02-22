/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:44:14 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/14 11:44:17 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		read_flags_from_format(char *frm)
{
	t_flags		*tmp;
	char		*all_flags;
	int			count;

	all_flags = "#0-+ ";
	tmp = (t_flags *)malloc(sizeof(tmp));
	g_printf = tmp;
	count = 0;
	clean_flags_struct();
	while (*frm && ft_strchr(all_flags, *frm) != 0)
	{
		if (*frm == '#')
			g_printf->flag_hesh = 1;
		else if (*frm == '-')
			g_printf->flag_minus = 1;
		else if (*frm == '+')
			g_printf->flag_plus = 1;
		else if (*frm == '0')
			g_printf->flag_zero = 1;
		else if (*frm == ' ')
			g_printf->flag_space = 1;
		frm++;
		count++;
	}
	return (continue_with_width(frm, count));
}

int		continue_with_width(char *frm, int count)
{
	int		res;

	res = 0;
	while (*frm >= '0' && *frm <= '9')
	{
		res = res * 10 + *frm - '0';
		frm++;
		count++;
	}
	g_printf->width = res;
	return (continue_with_precision(frm, count));
}

int		continue_with_precision(char *frm, int count)
{
	int		res;

	res = 0;
	if (*frm == '.')
	{
		frm++;
		count++;
		g_printf->precision_flag = 1;
		while (*frm >= '0' && *frm <= '9')
		{
			res = res * 10 + *frm - '0';
			frm++;
			count++;
		}
	}
	g_printf->precision = res;
	return (continue_with_size(frm, count));
}

int		continue_with_size(char *frm, int count)
{
	char	*all_sizes;

	all_sizes = "hljz";
	while (*frm && ft_strchr(all_sizes, *frm) != 0)
	{
		if (*frm == 'h' && *(frm + 1) == 'h')
			g_printf->size_hh = 1;
		else if (*frm == 'h' && *(frm + 1) != 'h')
			g_printf->size_h = 1;
		else if (*frm == 'l' && *(frm + 1) == 'l')
			g_printf->size_ll = 1;
		else if (*frm == 'l' && *(frm + 1) != 'l')
			g_printf->size_l = 1;
		else if (*frm == 'j')
			g_printf->size_j = 1;
		else if (*frm == 'z')
			g_printf->size_z = 1;
		frm++;
		count++;
	}
	return (count);
}

int		continue_with_conversions(char *frm, va_list ap)
{
	int		res_count;

	res_count = 0;
	g_printf->conver_letter = *frm;
	if (*frm == 'd' || *frm == 'i' || *frm == 'D')
		res_count = print_d_i_conversions(ap);
	else if (*frm == 'u' || *frm == 'U')
		res_count = print_u_o_x_p_conversion(ap, 10, 0);
	else if (*frm == 'o' || *frm == 'O')
		res_count = print_u_o_x_p_conversion(ap, 8, 0);
	else if (*frm == 'x' || *frm == 'p')
		res_count = print_u_o_x_p_conversion(ap, 16, 0);
	else if (*frm == 'X')
		res_count = print_u_o_x_p_conversion(ap, 16, 1);
	else if (*frm == 'S' || (*frm == 's' && g_printf->size_l == 1))
		res_count = print_utf_s_conversion(ap);
	else if (*frm == 's')
		res_count = print_s_conversion(ap);
	else if (*frm == 'C' || (*frm == 'c' && g_printf->size_l == 1))
		res_count = print_utf_c_conversion(ap);
	else if (*frm == 'c' || *frm != '\0')
		res_count = print_c_conversion(ap);
	if (!*frm)
		free(g_printf);
	return (res_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res_func_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:46:28 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/14 10:46:30 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		print_d_i_conversions(va_list ap)
{
	char	*width;
	char	*value;
	char	*res;
	int		res_len;

	width = set_width(1);
	value = cast_d_i_size(ap);
	if (value[0] == '0' && g_printf->precision_flag == 1
			&& g_printf->precision == 0)
		value[0] = '\0';
	res = set_flag_for_d_i_u(generate_res_for_int(width, value, 0));
	res_len = ft_strlen(res);
	ft_putstr(res);
	free(width);
	free(value);
	clean_memory_leaks(res);
	return (res_len);
}

int		print_u_o_x_p_conversion(va_list ap, int base, int up_case)
{
	char	*width;
	char	*value;
	char	*res;
	int		res_len;

	width = set_width(1);
	value = cast_u_o_x_p_size(ap, base, up_case);
	if (value[0] == '0')
	{
		if (g_printf->precision_flag == 1 && g_printf->precision == 0)
			value[0] = '\0';
		if (g_printf->conver_letter == 'x' || g_printf->conver_letter == 'X')
			g_printf->flag_hesh = 0;
	}
	res = set_flag_for_o_x_p(generate_res_for_int(width, value, 0));
	res_len = ft_strlen(res);
	ft_putstr(res);
	free(width);
	free(value);
	clean_memory_leaks(res);
	return (res_len);
}

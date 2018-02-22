/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:30:07 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/23 10:30:09 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*generate_res_for_int(char *width, char *value, int i)
{
	char	*res;
	int		width_len;
	int		value_len;

	width_len = ft_strlen(width);
	value_len = ft_strlen(value);
	if (width_len <= ((value[0] == '-') ? value_len - 1 : value_len))
		res = ft_strdup(value);
	else
	{
		while (value_len && value[value_len - 1] != '-')
			width[--width_len] = value[--value_len];
		while (width[i] && width[i] == ' ' && width[i + 1] == ' ')
			i++;
		if (width[i] == ' ' && value[0] == '-')
		{
			width[i] = '-';
			res = ft_strdup(width);
		}
		else if (width[i] != ' ' && value[0] == '-')
			res = ft_strjoin("-", width);
		else
			res = ft_strdup(width);
	}
	return (res);
}

char	*generate_res_for_str(char *width, char *value)
{
	char	*res;
	int		width_len;
	int		value_len;

	if (g_printf->precision_flag == 1)
		value[g_printf->precision] = '\0';
	width_len = ft_strlen(width);
	value_len = ft_strlen(value);
	if (width_len > value_len)
		res = ft_strjoin(width + value_len, value);
	else
		res = ft_strdup(value);
	return (res);
}

int		generate_and_print_utf_str(char *width, wchar_t *value)
{
	int		width_len;
	int		value_len;
	int		width_len_copy;

	width_len = ft_strlen(width);
	width_len_copy = width_len;
	value_len = ft_utf_strlen(value);
	if (width_len <= value_len)
		while (*value)
			ft_print_utf((unsigned int)*value++);
	else if (g_printf->flag_minus == 1)
	{
		while (*value)
			ft_print_utf((unsigned int)*value++);
		while (width_len_copy-- > value_len)
			ft_putchar(' ');
	}
	else
	{
		while (width_len_copy-- > value_len)
			ft_putchar(' ');
		while (*value)
			ft_print_utf((unsigned int)*value++);
	}
	return ((width_len <= value_len) ? value_len : width_len);
}

int		generate_and_print_utf_char(char *width, wchar_t value)
{
	int		width_len;
	int		value_len;

	width_len = ft_strlen(width);
	value_len = ft_utf_charlen(value);
	if (width_len <= value_len)
		ft_print_utf((unsigned int)value);
	else if (g_printf->flag_minus == 1)
	{
		ft_print_utf((unsigned int)value);
		while (width_len-- > value_len)
			ft_putchar(' ');
	}
	else
	{
		while (width_len-- > value_len)
			ft_putchar(' ');
		ft_print_utf((unsigned int)value);
	}
	return ((width_len <= value_len) ? value_len : width_len);
}

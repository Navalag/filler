/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:02:27 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/14 11:02:30 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*set_hesh_flag_for_octal(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (res[i] == ' ')
		i++;
	if (res[i] == '0')
		return (res);
	else if (i != 0)
		res[i - 1] = '0';
	else
	{
		tmp = ft_strjoin("0", res);
		free(res);
		res = tmp;
	}
	return (res);
}

char	*set_hesh_flag_for_hexadecimal(char *res)
{
	int		i;

	i = 0;
	while (res[i] == ' ' || (g_printf->flag_zero == 1 && res[i] == '0'))
		i++;
	if (i >= 2)
	{
		while (res[i - 1] == '0' && i > 0)
			i--;
		if (i >= 1)
		{
			res[i - 1] = (g_printf->conver_letter == 'X') ? 'X' : 'x';
			res[i - 2] = '0';
		}
		else
		{
			res[i + 1] = (g_printf->conver_letter == 'X') ? 'X' : 'x';
			res[i] = '0';
		}
	}
	else
		res = continue_with_hesh_flag(res, i);
	return (res);
}

char	*continue_with_hesh_flag(char *res, int i)
{
	char	*prefix;
	char	*tmp;

	prefix = (g_printf->conver_letter == 'X') ? "0X" : "0x";
	if (i == 1)
	{
		res[0] = (g_printf->conver_letter == 'X') ? 'X' : 'x';
		tmp = ft_strjoin("0", res);
		free(res);
		res = tmp;
	}
	else
	{
		tmp = ft_strjoin(prefix, res);
		free(res);
		res = tmp;
	}
	return (res);
}

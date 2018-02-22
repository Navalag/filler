/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 08:35:34 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/02 08:35:37 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*set_plus_flag(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (res[i] == ' ')
		i++;
	if (res[i] == '-')
		return (res);
	else if (res[i] != '-' && i != 0)
		res[i - 1] = '+';
	else
	{
		tmp = ft_strjoin("+", res);
		free(res);
		res = tmp;
	}
	return (res);
}

char	*set_space_flag(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	while (res[i] == ' ')
		i++;
	if (res[i] == '-')
		return (res);
	else if (res[i] != '-' && i != 0)
		res[i - 1] = ' ';
	else
	{
		tmp = ft_strjoin(" ", res);
		free(res);
		res = tmp;
	}
	return (res);
}

char	*set_minus_flag(char *res)
{
	int		i;

	i = 0;
	while (res[i] == ' ')
		i++;
	if (g_printf->flag_space == 1 && res[i] != '-' && res[i] != '+')
		i--;
	res = ft_memmove(res, res + i, ft_strlen(res) - i);
	ft_memset(res + (ft_strlen(res) - i), ' ', i);
	return (res);
}

char	*set_zero_flag(char *res)
{
	int		i;
	char	*tmp;

	i = 0;
	if (res[i] != ' ')
		return (res);
	else if ((tmp = ft_strchr(res, '-')) == NULL && g_printf->flag_space == 1
			&& g_printf->flag_plus == 0)
		i++;
	else if ((tmp = ft_strchr(res, '-')) != NULL ||
			(tmp = ft_strchr(res, '+')) != NULL)
	{
		res[0] = (*tmp == '-') ? '-' : '+';
		*tmp = '0';
		i++;
	}
	while (res[i] == ' ')
		res[i++] = '0';
	return (res);
}

char	*set_zero_flag_for_s(char *res)
{
	int		i;

	i = 0;
	if (res[i] != ' ')
		return (res);
	while (res[i] == ' ')
		res[i++] = '0';
	return (res);
}

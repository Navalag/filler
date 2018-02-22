/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:43:57 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/12 15:44:00 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 0xxxxxxx
** 110xxxxx 10xxxxxx
** 1110xxxx 10xxxxxx 10xxxxxx
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

#include <stdlib.h>
#include "../../inc/libft.h"

void	ft_print_utf(unsigned int utf_val)
{
	char	*res;

	res = ft_strnew(4);
	if (utf_val <= 0x7F)
		(utf_val == 0) ? ft_putchar(utf_val) : (res[0] = utf_val);
	else if (utf_val <= 0x7FF)
	{
		res[0] = utf_val >> 6 | 0xC0;
		res[1] = (utf_val & 0x3F) | 0x80;
	}
	else if (utf_val <= 0xE08080)
	{
		res[0] = utf_val >> 12 | 0xE0;
		res[1] = ((utf_val >> 6) & 0x3F) | 0x80;
		res[2] = (utf_val & 0x3F) | 0x80;
	}
	else
	{
		res[0] = utf_val >> 18 | 0xF0;
		res[1] = ((utf_val >> 12) & 0x3F) | 0x80;
		res[2] = ((utf_val >> 6) & 0x3F) | 0x80;
		res[3] = (utf_val & 0x3F) | 0x80;
	}
	ft_putstr(res);
	free(res);
}

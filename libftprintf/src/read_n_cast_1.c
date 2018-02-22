/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:28:25 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/23 10:28:28 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*cast_d_i_size(va_list ap)
{
	if (g_printf->conver_letter == 'D')
		return (ft_itoa(va_arg(ap, long int)));
	else if (g_printf->size_z == 1)
		return (ft_itoa(va_arg(ap, intmax_t)));
	else if (g_printf->size_j == 1)
		return (ft_itoa(va_arg(ap, intmax_t)));
	else if (g_printf->size_ll == 1)
		return (ft_itoa(va_arg(ap, intmax_t)));
	else if (g_printf->size_l == 1)
		return (ft_itoa(va_arg(ap, long int)));
	else if (g_printf->size_hh == 1)
		return (ft_itoa((signed char)va_arg(ap, int)));
	else if (g_printf->size_h == 1)
		return (ft_itoa((short)va_arg(ap, int)));
	else
		return (ft_itoa(va_arg(ap, int)));
}

char	*cast_u_o_x_p_size(va_list ap, int base, int up_case)
{
	if (g_printf->conver_letter == 'U')
		return (ft_itoa_base_u(va_arg(ap, unsigned long), base, up_case));
	else if (g_printf->conver_letter == 'O')
		return (ft_itoa_base_u(va_arg(ap, unsigned long), base, up_case));
	else if (g_printf->conver_letter == 'p')
		return (ft_itoa_base_u(va_arg(ap, size_t), base, up_case));
	else if (g_printf->size_z == 1)
		return (ft_itoa_base_u(va_arg(ap, size_t), base, up_case));
	else if (g_printf->size_j == 1)
		return (ft_itoa_base_u(va_arg(ap, uintmax_t), base, up_case));
	else if (g_printf->size_ll == 1)
		return (ft_itoa_base_u(va_arg(ap, uintmax_t), base, up_case));
	else if (g_printf->size_l == 1)
		return (ft_itoa_base_u(va_arg(ap, unsigned long), base, up_case));
	else if (g_printf->size_hh == 1)
		return (ft_itoa_base_u((unsigned char)va_arg(ap, int), base, up_case));
	else if (g_printf->size_h == 1)
		return (ft_itoa_base_u((unsigned short)va_arg(ap, int),
															base, up_case));
	else
		return (ft_itoa_base_u(va_arg(ap, unsigned int), base, up_case));
}

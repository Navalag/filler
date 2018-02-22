/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:04:54 by agalavan          #+#    #+#             */
/*   Updated: 2018/01/11 11:04:56 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "../libft/inc/libft.h"

typedef struct	s_fl
{
	unsigned	flag_hesh:1;
	unsigned	flag_minus:1;
	unsigned	flag_plus:1;
	unsigned	flag_zero:1;
	unsigned	flag_space:1;
	int			width;
	int			precision;
	unsigned	precision_flag:1;
	unsigned	size_hh:1;
	unsigned	size_h:1;
	unsigned	size_ll:1;
	unsigned	size_l:1;
	unsigned	size_j:1;
	unsigned	size_z:1;
	char		conver_letter;
}				t_flags;

t_flags		*g_printf;

/*
** main function
*/

int				ft_printf(char *fmt, ...);

/*
** read_flags functions
*/

int				read_flags_from_format(char *frm);
int				continue_with_width(char *frm, int count);
int				continue_with_precision(char *frm, int count);
int				continue_with_size(char *frm, int count);
int				continue_with_conversions(char *frm, va_list ap);

/*
** print_result functions
*/

char			*generate_res_for_int(char *width, char *value, int i);
char			*generate_res_for_str(char *width, char *value);
int				generate_and_print_utf_str(char *width, wchar_t *value);
int				generate_and_print_utf_char(char *width, wchar_t value);

int				print_d_i_conversions(va_list ap);
int				print_u_o_x_p_conversion(va_list ap, int base, int up_case);

int				print_s_conversion(va_list ap);
int				print_utf_s_conversion(va_list ap);
int				print_c_conversion(va_list ap);
int				print_utf_c_conversion(va_list ap);

/*
** set width and precision functions
*/

char			*set_int_precision(char *res);
char			*set_width(int prec_y_n);

/*
** read and cast argument functions
*/

char			*cast_d_i_size(va_list ap);
char			*cast_u_o_x_p_size(va_list ap, int base, int up_case);

char			*cast_s_size(va_list ap);
wchar_t			*cast_utf_s_size(va_list ap);
char			cast_c_size(va_list ap);
wchar_t			cast_utf_c_size(va_list ap);

/*
** set flags functions
*/

char			*set_flag_for_d_i_u(char *res);
char			*set_flag_for_o_x_p(char *res);
char			*set_flag_for_s(char *res);
int				set_flag_for_c(char *width, char value, int width_len, int i);

char			*set_plus_flag(char *res);
char			*set_space_flag(char *res);
char			*set_minus_flag(char *res);
char			*set_zero_flag(char *res);
char			*set_zero_flag_for_s(char *res);

char			*set_hesh_flag_for_octal(char *res);
char			*set_hesh_flag_for_hexadecimal(char *res);
char			*continue_with_hesh_flag(char *res, int i);

/*
** additional functions
*/

void			clean_flags_struct(void);
int				ft_utf_strlen(wchar_t *value);
int				ft_utf_charlen(wchar_t value);
void			clean_memory_leaks(char *res);

#endif

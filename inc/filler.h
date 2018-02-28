/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:15:51 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/22 11:15:54 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libftprintf/inc/ft_printf.h"

typedef struct	s_board
{
	char	x_o_team;
	char	**board;
	char	**token;
	int		x_max;
	int		y_max;
	int		x_token;
	int		y_token;

	int 	fd_test;
}				t_game_elem;

typedef struct	s_cpu
{
	int		x;
	int		y;
	int		cpu;
}				t_cpu;

typedef struct	s_res
{
	int		x;
	int		y;
	int		diff_x;
	int		diff_y;
}				t_res;

t_game_elem		*g_filler;
t_cpu			*g_cpu;
t_res			*g_res;

void	fill_token_with_figure(int fd);
void	fill_board_with_lines(int fd);
void	read_input_and_fill_struct(int fd);

void	make_next_step(void);
void	max_cpu(int cpu, int x, int y, t_cpu *cpu_head);
int		find_cpu(int x, int y);
int		check_figure(int x, int y);
t_cpu	*create_n_clean_cpu_struct();

int		check_current_token_line(int j);
int		check_prev_line(int y);
int		abc(int i);
int		max_int(int i, int j);
int		check_next_line(int y);

#endif

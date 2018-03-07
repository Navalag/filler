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
	int		x_board_max;
	int		y_board_max;
	int		x_token_max;
	int		y_token_max;
}				t_game_elem;

typedef struct	s_cpu
{
	int		x;
	int		y;
	int		cpu;
}				t_cpu;

t_game_elem		*g_f;
t_cpu			*g_cpu;

/*
** read input and main functions
*/

void			fill_token_with_figure(void);
void			fill_board_with_lines(void);
void			make_next_step(void);

/*
** index all board functions
*/

void			index_all_board(char ch);
void			check_and_surround(int x, int y, unsigned char i, char ch);
void			surround_with_numbers(int x, int y, unsigned char i);
int				check_free_space(void);

/*
** find next step functions
*/

void			find_best_move(char ch);
int				check_figure(char ch, int x, int y, int copy_x);
void			best_cpu(int tmp_cpu, int x, int y);
int				find_cpu(char ch, int x, int y);

/*
** aditional functions
*/

void			insert_begin_val_to_struct(void);
void			clean_all_structs(void);

#endif

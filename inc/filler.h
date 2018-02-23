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
}				t_game_elem;

t_game_elem		*g_filler;

void	fill_token_with_figure(int fd);
void	fill_board_with_lines(int fd);
void	read_input_and_fill_struct(int fd);

void	find_best_move(void);
void	find_opponent(char ch);
int		check_neighbors(int y, int x);
void	surround_with_numbers(int y, int x, int i);

#endif

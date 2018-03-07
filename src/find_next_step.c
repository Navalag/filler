/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:44:01 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/23 16:44:04 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
** Next block of functions find best move for our bot.
**
** For this reason in find_best_move() we use 3 steps:
** 1) check figure - if current position valid (has only one touch with
** our territory, does not touch opponent and every piece of figure '*' can
** be placed on the board).
** 2) find cpu - calculate all indexes on which we want to place figure.
** 3) best cpu - put into the structure coordinates with lowest cpu
** which means the closest to the opponent.
*/

void	find_best_move(char ch)
{
	int		y;
	int		x;

	y = 0;
	while (y < g_f->y_board_max)
	{
		x = 0;
		while (x < g_f->x_board_max)
		{
			if ((g_f->y_token_max + y) >= g_f->y_board_max + 1 ||
				(g_f->x_token_max + x) >= g_f->x_board_max + 1)
				;
			else if (check_figure(ch, x, y, x))
				best_cpu(find_cpu(ch, x, y), x, y);
			x++;
		}
		y++;
	}
}

int		check_figure(char ch, int x, int y, int copy_x)
{
	int		i;
	int		j;
	int		index;

	j = 0;
	index = 0;
	while (j < g_f->y_token_max && y < g_f->y_board_max)
	{
		i = 0;
		x = copy_x;
		while (i < g_f->x_token_max && x < g_f->x_board_max)
		{
			if (g_f->token[j][i] == '*' && g_f->board[y][x] == ch)
				index++;
			if (index > 1 || (g_f->token[j][i] == '*'
				&& (g_f->board[y][x] == (ch == 'O' ? 'x' : 'o')
				|| g_f->board[y][x] == (ch == 'O' ? 'X' : 'O'))))
				return (0);
			i++;
			x++;
		}
		j++;
		y++;
	}
	return (index == 1 ? 1 : 0);
}

void	best_cpu(int tmp_cpu, int x, int y)
{
	if (tmp_cpu < g_cpu->cpu)
	{
		g_cpu->x = x;
		g_cpu->y = y;
		g_cpu->cpu = tmp_cpu;
	}
}

int		find_cpu(char ch, int x, int y)
{
	int		i;
	int		j;
	int		cpu;
	int		copy_x;

	j = 0;
	cpu = 0;
	copy_x = x;
	while (j < g_f->y_token_max)
	{
		i = 0;
		x = copy_x;
		while (i < g_f->x_token_max)
		{
			if (g_f->token[j][i] == '*'
					&& g_f->board[y][x] != (ch == 'O' ? 'O' : 'X'))
				cpu += g_f->board[y][x];
			i++;
			x++;
		}
		y++;
		j++;
	}
	return (cpu);
}

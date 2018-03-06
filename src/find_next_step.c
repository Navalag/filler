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
			if (check_figure(ch, x, y))
				best_cpu(find_cpu(ch, x, y), x, y);
			x++;
		}
		y++;
	}
	// int d = -1;
	// while (++d < 24)
	// 	ft_printf("%s\n", g_f->board[d]);
}

int		check_figure(char ch, int x, int y)
{
	int		i;
	int		j;
	int		index;
	int		copy_x;

	j = 0;
	index = 0;
	copy_x = x;
	if ((g_f->y_token_max + y) >= g_f->y_board_max + 1 ||
		(g_f->x_token_max + x) >= g_f->x_board_max + 1)
		return (0);
	while (j < g_f->y_token_max && y < g_f->y_board_max)
	{
		i = 0;
		x = copy_x;
		while (i < g_f->x_token_max && x < g_f->x_board_max)
		{
			if (g_f->token[j][i] == '*' && g_f->board[y][x] == ch)
				index++;
			if (index > 1 || ((g_f->board[y][x] == (ch == 'O' ? 'X' : 'O')
				|| g_f->board[y][x] == (ch == 'O' ? 'x' : 'o'))
				&& g_f->token[j][i] == '*'))
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

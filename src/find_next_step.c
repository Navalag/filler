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

void	clean_structs(void)
{
	g_cpu->x = 0;
	g_cpu->y = 0;
	g_cpu->cpu = 10000;
}

void	make_next_step(void)
{
	g_cpu = (t_cpu *)malloc(sizeof(*g_cpu));
	clean_structs();
	if (g_f->x_o_team == 'O')
		index_all_board('X');
	else
		index_all_board('O');
	find_best_move(g_f->x_o_team);
}

void	index_all_board(char ch)
{
	int				y;
	int				x;
	unsigned char	i;
	int				index;

	i = '0';
	index = 0;
	while (check_free_space()) // can be bug with 'X' 'O' indexes
	{
		y = 0;
		while (y < g_f->y_max)
		{
			x = 0;
			while (x < g_f->x_max)
			{
				if (index == 1 && g_f->board[y][x] == i - 2)
					surround_with_numbers(x, y, i);
				else if (g_f->board[y][x] == i - 1)
					surround_with_numbers(x, y, i);
				else if ((g_f->board[y][x] == ch || g_f->board[y][x] == ch + 32))
					surround_with_numbers(x, y, i);
				x++;
			}
			y++;
		}
		i++;
		index = 0;
		if (i == 'X' || i == 'x' || i == 'O' || i == 'o')
		{
			i++;
			index = 1;
		}
	}
}

int		check_free_space(void)
{
	int		x;
	int		y;

	y = 0;
	while (y < g_f->y_max)
	{
		x = 0;
		while (x < g_f->x_max)
		{
			if (g_f->board[y][x] == '.')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	surround_with_numbers(int x, int y, unsigned char i)
{
	if (x >= 1 && g_f->board[y][x - 1] == '.')
		g_f->board[y][x - 1] = i;
	if (x < g_f->x_max - 1 && g_f->board[y][x + 1] == '.')
		g_f->board[y][x + 1] = i;
	if (y >= 1 && g_f->board[y - 1][x] == '.')
		g_f->board[y - 1][x] = i;
	if (y < g_f->y_max - 1 && g_f->board[y + 1][x] == '.')
		g_f->board[y + 1][x] = i;
	if (y >= 1 && x >= 1 && g_f->board[y - 1][x - 1] == '.')
		g_f->board[y - 1][x - 1] = i;
	if (y >= 1 && x < g_f->x_max - 1 && g_f->board[y - 1][x + 1] == '.')
		g_f->board[y - 1][x + 1] = i;
	if (y < g_f->y_max - 1 && x >= 1 && g_f->board[y + 1][x - 1] == '.')
		g_f->board[y + 1][x - 1] = i;
	if (y < g_f->y_max - 1 && x < g_f->x_max - 1 &&
			g_f->board[y + 1][x + 1] == '.')
		g_f->board[y + 1][x + 1] = i;
}

void	find_best_move(char ch)
{
	int		y;
	int		x;

	y = 0;
	while (y < g_f->y_max)
	{
		x = 0;
		while (x < g_f->x_max)
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
	if ((g_f->y_token + y) >= g_f->y_max + 1 ||
		(g_f->x_token + x) >= g_f->x_max + 1)
		return (0);
	while (j < g_f->y_token && y < g_f->y_max)
	{
		i = 0;
		x = copy_x;
		while (i < g_f->x_token && x < g_f->x_max)
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
	while (j < g_f->y_token)
	{
		i = 0;
		x = copy_x;
		while (i < g_f->x_token)
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

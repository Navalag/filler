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

void	make_next_step(void)
{
	g_cpu = (t_cpu *)malloc(sizeof(*g_cpu));
	g_res = (t_res *)malloc(sizeof(*g_res));
	if (g_filler->x_o_team == 'O')
	{
		index_all_board('O');
		find_best_move('O');
	}
	else if (g_filler->x_o_team == 'X')
	{
		index_all_board('X');
		find_best_move('X');
	}
	find_result();
}

void	index_all_board(char ch)
{
	int				y;
	int				x;
	unsigned char	i;

	i = 0;
	while (ft_strchr(g_filler->board[0], '.'))
	{
		y = 0;
		i++;
		while (y < g_filler->y_max)
		{
			x = 0;
			while (x < g_filler->x_max)
			{
				if (g_filler->board[y][x] == i - 1)
					surround_with_numbers(x, y, i);
				else if (i == 1 && (g_filler->board[y][x] == ch ||
						g_filler->board[y][x] == ch + 32))
					surround_with_numbers(x, y, i);
				x++;
			}
			y++;
		}
	}
}

void	surround_with_numbers(int x, int y, unsigned char i)
{
	if (g_filler->board[y][x - 1] == '.')
		g_filler->board[y][x - 1] = i;
	if (g_filler->board[y][x + 1] == '.')
		g_filler->board[y][x + 1] = i;
	if (g_filler->board[y - 1][x] == '.')
		g_filler->board[y - 1][x] = i;
	if (g_filler->board[y + 1][x] == '.')
		g_filler->board[y + 1][x] = i;
	if (g_filler->board[y - 1][x - 1] == '.')
		g_filler->board[y - 1][x - 1] = i;
	if (g_filler->board[y - 1][x + 1] == '.')
		g_filler->board[y - 1][x + 1] = i;
	if (g_filler->board[y + 1][x - 1] == '.')
		g_filler->board[y + 1][x - 1] = i;
	if (g_filler->board[y + 1][x + 1] == '.')
		g_filler->board[y + 1][x + 1] = i;
}

void	find_best_move(char ch)
{
	int		y;
	int		x;

	y = 0;
	while (y < g_filler->y_max)
	{
		x = 0;
		while (x < g_filler->x_max)
		{
			if (check_figure(x, y))
				best_cpu(find_cpu(x, y), x, y);
			x++;
		}
		y++;
	}
}

int		check_figure(int x, int y)
{
	int		i;
	int		j;
	int		index;

	j = 0;
	index = 0;
	while (j < g_filler->y_token)
	{
		i = 0;
		while (i < g_filler->x_token)
		{
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] == 'O')
			{
				index++;
				x++;
			}
			if (index > 1 || g_filler->board[y][x] == 'X' ||
				g_filler->board[y][x] == 'x')
				return (0);
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] != 'O')
				x++;
			i++;
		}
		if (check_current_token_line(j))
			y++;
		j++;
	}
	return ((index == 1) ? 1 : 0);
}

int		check_current_token_line(int j)
{
	int		i;

	i = g_filler->x_token;
	while (i--)
	{
		if (g_filler->token[j][i] == '*')
			return (1);
	}
	return (0);
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

int		find_cpu(int x, int y)
{
	int		i;
	int		j;
	int		cpu;

	j = 0;
	cpu = 0;
	while (j < g_filler->y_token)
	{
		i = 0;
		while (i < g_filler->x_token)
		{
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] == 'O')
				x++;
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] != 'O')
			{
				cpu += g_filler->board[y][x];
				x++;
			}
			i++;
		}
		if (check_current_token_line(j))
			y++;
		j++;
	}
	return (cpu);
}

void	find_result(void)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < g_filler->y_token)
	{
		x = 0;
		while (x < g_filler->x_token)
		{
			if (g_filler->token[y][x] == '*')
				if (x < g_res->diff_x)
					g_res->diff_x = x;
			x++;
		}
		if (check_current_token_line(y))
			if (y < g_res->diff_y)
				g_res->diff_y = y;
		y++;
	}
	g_res->y = g_cpu->y - g_res->diff_y;
	g_res->x = g_cpu->x - g_res->diff_x;
}

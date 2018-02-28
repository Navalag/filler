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

void	find_best_move(void)
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

bool	check_figure(int x, int y)
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
				return (false);
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] != 'O')
				x++;
			i++;
		}
		if (check_current_token_line(j))
			y++;
		j++;
	}
	return ((index == 1) ? true : false);
}

bool	check_current_token_line(int j)
{
	int		i;

	i = g_filler->x_token;
	while (i--)
	{
		if (g_filler->token[j][i] == '*')
			return (true);
	}
	return (false);
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

void	find_result()
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











void	make_next_step(void)
{
	int		tmp_x;
	int		tmp_y;
	int		y;
	int		x;
	t_cpu	*cpu_head;

	y = 0;
	cpu_head = create_n_clean_cpu_struct();
	while (y < g_filler->y_max)
	{
		x = 0;
		while (x < g_filler->x_max)
		{
			if (g_filler->board[y][x] == 'O' && check_figure(x, y) &&
				check_next_line(y + 1))
				max_cpu(find_cpu(x, y), x, y, cpu_head);
			else if (g_filler->board[y][x] == 'O' && check_figure(x, y))
			{
				tmp_x = x;
				tmp_y = y;
			}
			x++;
		}
		if (!(check_next_line(y + 1)))
			max_cpu(find_cpu(x, y), tmp_x, tmp_y, cpu_head);
		y++;
	}
}

void	max_cpu(int cpu, int x, int y, t_cpu *cpu_head)
{
	if (cpu_head->cpu < cpu)
	{
		cpu_head->x = x;
		cpu_head->y = y;
		cpu_head->cpu = cpu;
	}
}

int		find_cpu(int x, int y)
{
	int		j;
	int		i;
	int		opponent_x;
	int		opponent_y;
	int		cpu;

	j = g_filler->y_max;
	cpu = 0;
	while (j--)
	{
		i = g_filler->x_max;
		while (i--)
		{
			if ((g_filler->board[j][i] == 'X' || g_filler->board[j][i] == 'x') &&
				check_prev_line(j - 1))
				cpu = max_int(abc(j - y), abc(i - x));
			else if (g_filler->board[j][i] == 'X' || g_filler->board[j][i] == 'x')
			{
				opponent_x = i;
				opponent_y = j;
			}
		}
		if (!(check_prev_line(j - 1)))
			cpu = max_int(abc(opponent_y - y), abc(opponent_x - x));
	}
	return (cpu);
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
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] != '.')
			{
				index++;
				x++;
			}
			if (index > 1)
				return (0);
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] == '.')
				x++;
			i++;
		}
		if (check_current_token_line(j))
			y++;
		j++;
	}
	return (1);
}

t_cpu	*create_n_clean_cpu_struct()
{
	t_cpu	*cpu;

	cpu = (t_cpu *)malloc(sizeof(*cpu));
	cpu->x = 0;
	cpu->y = 0;
	cpu->cpu = 0;
	return (cpu);
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

int		check_prev_line(int y)
{
	int		x;

	x = g_filler->x_max;
	while (x--)
	{
		if (g_filler->board[y][x] == 'X' || g_filler->board[y][x] == 'x')
			return (0);
	}
	return (1);
}

int		abc(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int		max_int(int i, int j)
{
	if (i <= j)
		return (j);
	return (i);
}

int		check_next_line(int y)
{
	int		x;

	x = 0;
	while (x < g_filler->x_max)
	{
		if (g_filler->board[y][x] == 'O')
			return (0);
		x++;
	}
	return (1);
}

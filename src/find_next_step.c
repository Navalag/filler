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

void	make_next_step()
{
	int		tmp_x;
	int		tmp_y;
	int		y;
	int		x;
	t_cpu	cpu_head;

	y = 0;
	cpu_head = create_n_clean_cpu_struct(cpu_head);
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
			max_cpu(find_cpu(x, y), tmp_x, tmp_y);
		y++;
	}
}

void	create_n_clean_cpu_struct(t_cpu cpu)
{
	cpu = (t_cpu)malloc(sizeof(cpu));
	cpu.x = 0;
	cpu.y = 0;
	cpu.cpu = 0;
}

void	max_cpu(int cpu, int x, int y, t_cpu cpu)
{
	if (tmp.cpu < cpu)
	{
		tmp.x = x;
		tmp.y = y;
	}
}

int		find_cpu(int x, int y)
{
	int		j;
	int		i;
	int		cpu;

	j = g_filler->y_max;
	cpu = 0;
	while (j--)
	{
		i = g_filler->x_max;
		while (i--)
		{
			if ((g_filler->board[j][i] == 'X' || g_filler->board[j][i] == 'x') &&
				check_prev_line(j + 1))
				cpu = max_int(abc(j - y), abc(i - x));
			else if (g_filler->board[j][i] == 'X' || g_filler->board[j][i] == 'x')
			{
				opponent_x = i;
				opponent_y = j;
			}
		}
		if (!(check_prev_line(j + 1)))
			cpu = max_int(abc(opponent_y - y), abc(opponent_x - x));
	}
	return (cpu);
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
				index++;
			if (index > 1)
				return (0);
			i++;
			x++;
		}
		j++;
		y++;
	}
	return (1);
}

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

void	clean_cpu_and_res_structs(void)
{
	g_cpu->x = 0;
	g_cpu->y = 0;
	g_cpu->cpu = 10000;
	g_res->x = 0;
	g_res->y = 0;
	g_res->diff_x = g_filler->x_token;
	g_res->diff_y = g_filler->y_token;
}

void	make_next_step(void)
{
	g_cpu = (t_cpu *)malloc(sizeof(*g_cpu));
	g_res = (t_res *)malloc(sizeof(*g_res));
	clean_cpu_and_res_structs();
	if (g_filler->x_o_team == 'O')
	{
		index_all_board('X');
		find_best_move();
	}
	else if (g_filler->x_o_team == 'X')
	{
		index_all_board('O');
		find_best_move();
	}
}

void	index_all_board(char ch)
{
	int				y;
	int				x;
	unsigned char	i;

	i = '0';
	while (ft_strchr(g_filler->board[0], '.')) // can be bug with 'X' 'O' indexes
	{
		y = 0;
		while (y < g_filler->y_max)
		{
			x = 0;
			while (x < g_filler->x_max)
			{
				if (g_filler->board[y][x] == i - 1)
					surround_with_numbers(x, y, i);
				else if ((g_filler->board[y][x] == ch ||
						g_filler->board[y][x] == ch + 32))
					surround_with_numbers(x, y, i);
				x++;
			}
			y++;
		}
		i++;
	}
	// if (g_filler->board[y][x] == 'X'
	// || g_filler->board[y][x] == 'x'
	// || g_filler->board[y][x] == 'O'
	// || g_filler->board[y][x] == 'o')
	// 	i++;
}

void	surround_with_numbers(int x, int y, unsigned char i)
{
	if (x >= 1 && g_filler->board[y][x - 1] == '.')
		g_filler->board[y][x - 1] = i;
	if (x < g_filler->x_max - 1 && g_filler->board[y][x + 1] == '.')
		g_filler->board[y][x + 1] = i;
	if (y >= 1 && g_filler->board[y - 1][x] == '.')
		g_filler->board[y - 1][x] = i;
	if (y < g_filler->y_max - 1 && g_filler->board[y + 1][x] == '.')
		g_filler->board[y + 1][x] = i;
	if (y >= 1 && x >= 1 && g_filler->board[y - 1][x - 1] == '.')
		g_filler->board[y - 1][x - 1] = i;
	if (y >= 1 && x < g_filler->x_max - 1 && g_filler->board[y - 1][x + 1] == '.')
		g_filler->board[y - 1][x + 1] = i;
	if (y < g_filler->y_max - 1 && x >= 1 && g_filler->board[y + 1][x - 1] == '.')
		g_filler->board[y + 1][x - 1] = i;
	if (y < g_filler->y_max - 1 && x < g_filler->x_max - 1 &&
			g_filler->board[y + 1][x + 1] == '.')
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
	// int d = -1;
	// while (d++ < 23)
	// 	ft_printf("%s\n", g_filler->board[d]);
}

int		check_figure(int x, int y)
{
	int		i;
	int		j;
	int		index;
	int		copy_x;

	j = 0;
	index = 0;
	copy_x = x;
	if ((g_filler->y_token + y) <= g_filler->y_max + 1 ||
		(g_filler->x_token + x) <= g_filler->x_max + 1)
		return (0);
	while (j < g_filler->y_token && y < g_filler->y_max)
	{
		i = 0;
		x = copy_x;
		while (i < g_filler->x_token && x < g_filler->x_max)
		{
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] == 'O')
				index++;
			if (index > 1 || ((g_filler->board[y][x] == 'X' ||
				g_filler->board[y][x] == 'x') && g_filler->token[j][i] == '*'))
				return (0);
			i++;
			x++;
		}
		j++;
		y++;
	}
	// if (index == 1)
	// {
	// 	ft_printf("g_cpu->x = %d\n", g_cpu->x);
	// 	ft_printf("g_cpu->y = %d\n", g_cpu->y);
	// 	ft_printf("g_cpu->cpu = %d\n", g_cpu->cpu);
	// 	ft_printf("index = %d\n", index);
	// }
	return (index == 1 ? 1 : 0);
}

void	best_cpu(int tmp_cpu, int x, int y)
{
	ft_printf("\ntmp_cpu = %d\n", tmp_cpu);
	ft_printf("x = %d\n", x);
	ft_printf("y = %d\n", y);
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
	int		copy_x;

	j = 0;
	cpu = 0;
	copy_x = x;
	while (j < g_filler->y_token)
	{
		i = 0;
		x = copy_x;
		while (i < g_filler->x_token)
		{
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] != 'O')
				cpu += g_filler->board[y][x];
			i++;
			x++;
		}
		y++;
		j++;
	}
	return (cpu);
}

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
	// find_result();
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
}

int		check_figure(int x, int y)
{
	int		i;
	int		j;
	int		index;

	j = 0;
	index = 0;
	while (j < g_filler->y_token && y < g_filler->y_max)
	{
		i = 0;
		while (i < g_filler->x_token && x < g_filler->x_max)
		{
			if (g_filler->token[j][i] == '*' && g_filler->board[y][x] == 'O')
				index++;
			if (index > 1 || g_filler->board[y][x] == 'X' ||
				g_filler->board[y][x] == 'x')
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
		ft_printf("x = %d\ny = %d\n", x, y);
		ft_printf("cpu = %d\n", tmp_cpu);
		ft_printf("g_cpu->x = %d\ng_cpu->y = %d\n", g_cpu->x, g_cpu->y);
		ft_printf("g_cpu->cpu = %d\n", g_cpu->cpu);
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
			else if (g_filler->token[j][i] == '*' && g_filler->board[y][x] != 'O')
			{
				cpu += g_filler->board[y][x];
				x++;
			}
			i++;
		}
		if (ft_strchr(g_filler->token[j], '*'))
			y++;
		j++;
	}
	return (cpu);
}

// void	find_result(void)
// {
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (y < g_filler->y_token)
// 	{
// 		x = 0;
// 		while (x < g_filler->x_token)
// 		{
// 			if (g_filler->token[y][x] == '*')
// 				if (x < g_res->diff_x)
// 					g_res->diff_x = x;
// 			x++;
// 		}
// 		if (ft_strchr(g_filler->token[y], '*'))
// 			if (y < g_res->diff_y)
// 				g_res->diff_y = y;
// 		y++;
// 	}
// 	g_res->y = g_cpu->y - g_res->diff_y;
// 	g_res->x = g_cpu->x - g_res->diff_x;
// }

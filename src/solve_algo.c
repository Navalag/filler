/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 10:51:10 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/23 10:51:13 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	find_best_move(void)
{
	ft_printf("check");
	if (g_filler->x_o_team == 'O')
		find_opponent('X');
	else
		find_opponent('O');
}

void	find_opponent(char ch)
{
	int		y;
	int		x;
	int		i;
	int		break_flag;

	i = 1;
	break_flag = 1;
	while (break_flag)
	{
		y = 0;
		while (y < g_filler->y_max)
		{
			x = 0;
			while (x < g_filler->x_max)
			{
				if (g_filler->board[y][x] == 'O' && check_neighbors(y, x))
					break_flag = 0;
				if (g_filler->board[y][x] == ch || g_filler->board[y][x] == (ch + 32))
					surround_with_numbers(y, x, i++);
				x++;
			}
			y++;
		}
	}
}

int		check_neighbors(int y, int x)
{
	if (g_filler->board[y][x - 1] != '.' && g_filler->board[y][x] != 'O')
		return (1);
	if (g_filler->board[y][x + 1] != '.' && g_filler->board[y][x] != 'O')
		return (1);
	if (g_filler->board[y - 1][x] != '.' && g_filler->board[y][x] != 'O')
		return (1);
	if (g_filler->board[y + 1][x] != '.' && g_filler->board[y][x] != 'O')
		return (1);
	if (g_filler->board[y - 1][x - 1] != '.' && g_filler->board[y][x] != 'O')
		return (1);
	if (g_filler->board[y - 1][x + 1] != '.' && g_filler->board[y][x] != 'O')
		return (1);
	if (g_filler->board[y + 1][x - 1] != '.' && g_filler->board[y][x] != 'O')
		return (1);
	if (g_filler->board[y + 1][x + 1] != '.' && g_filler->board[y][x] != 'O')
		return (1);
	return (0);
}

void	surround_with_numbers(int y, int x, int i)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_board_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:33:08 by agalavan          #+#    #+#             */
/*   Updated: 2018/03/06 10:33:10 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
** Following function make 3 loops:
** 1) until there are '.' (free positions on the map);
** 2) iterate lines;
** 3) iterate columns;
**
** At the end bot has map where opponent surrounded with numbers which shows
** distace to our territory.
*/

void	index_all_board(char ch)
{
	int				y;
	int				x;
	unsigned char	i;

	i = '0';
	while (check_free_space() && i < 255)
	{
		y = 0;
		while (y < g_f->y_board_max)
		{
			x = 0;
			while (x < g_f->x_board_max)
			{
				check_and_surround(x, y, i, ch);
				x++;
			}
			y++;
		}
		i++;
	}
}

int		check_free_space(void)
{
	int		x;
	int		y;

	y = 0;
	while (y < g_f->y_board_max)
	{
		x = 0;
		while (x < g_f->x_board_max)
		{
			if (g_f->board[y][x] == '.')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_and_surround(int x, int y, unsigned char i, char ch)
{
	int		index;

	index = 0;
	if (i == 'X' || i == 'x' || i == 'O' || i == 'o')
	{
		i++;
		index = 1;
	}
	if (index == 1 && g_f->board[y][x] == i - 2)
		surround_with_numbers(x, y, i);
	else if (g_f->board[y][x] == i - 1)
		surround_with_numbers(x, y, i);
	else if ((g_f->board[y][x] == ch || g_f->board[y][x] == ch + 32))
		surround_with_numbers(x, y, i);
}

/*
** Following function take coordinates of one cell of the shape
** and check all 8 sides arround it. If function find '.' then it
** change '.' to the given index 'i'.
** Also the shape must not exceed the dimensions of the board
** so we check it in every 'if' condition.
*/

void	surround_with_numbers(int x, int y, unsigned char i)
{
	if (x >= 1 && g_f->board[y][x - 1] == '.')
		g_f->board[y][x - 1] = i;
	if (x < g_f->x_board_max - 1 && g_f->board[y][x + 1] == '.')
		g_f->board[y][x + 1] = i;
	if (y >= 1 && g_f->board[y - 1][x] == '.')
		g_f->board[y - 1][x] = i;
	if (y < g_f->y_board_max - 1 && g_f->board[y + 1][x] == '.')
		g_f->board[y + 1][x] = i;
	if (y >= 1 && x >= 1 && g_f->board[y - 1][x - 1] == '.')
		g_f->board[y - 1][x - 1] = i;
	if (y >= 1 && x < g_f->x_board_max - 1 && g_f->board[y - 1][x + 1] == '.')
		g_f->board[y - 1][x + 1] = i;
	if (y < g_f->y_board_max - 1 && x >= 1 && g_f->board[y + 1][x - 1] == '.')
		g_f->board[y + 1][x - 1] = i;
	if (y < g_f->y_board_max - 1 && x < g_f->x_board_max - 1 &&
			g_f->board[y + 1][x + 1] == '.')
		g_f->board[y + 1][x + 1] = i;
}

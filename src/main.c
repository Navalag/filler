/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:50:20 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/20 09:50:23 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	fill_token_with_figure(void)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	g_f->y_token_max = ft_atoi(line + 6);
	while (ft_isdigit(*(line + 6 + i)))
		i++;
	g_f->x_token_max = ft_atoi(line + 6 + i);
	g_f->token = (char **)malloc(sizeof(char *) * g_f->y_token_max + 1);
	g_f->token[g_f->y_token_max] = 0;
	free(line);
	i = 0;
	while (i < g_f->y_token_max)
	{
		get_next_line(0, &line);
		g_f->token[i] = ft_strdup(line);
		free(line);
		i++;
	}
}

void	fill_board_with_lines(void)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	free(line);
	while (i < g_f->y_board_max)
	{
		get_next_line(0, &line);
		g_f->board[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	fill_token_with_figure();
}

void	make_next_step(void)
{
	g_cpu = (t_cpu *)malloc(sizeof(*g_cpu));
	insert_begin_val_to_struct();
	if (g_f->x_o_team == 'O')
		index_all_board('X');
	else
		index_all_board('O');
	find_best_move(g_f->x_o_team);
}

/*
** Following bot algorithm is divided into 3 parts:
** 1 - read input data from vm. This functions can be find in main.c file.
** 2 - index all positions on the board according their distance from
** the opponent. File index_board_func.c
** 3 - find next step. After all positions are indexed, bot can
** choose where is the best place to put the given figure.
**
** At the very end bot prints "Y, X\n" coordinates for vm (virtual machine)
** and clean all malloc allocated memory.
*/

int		main(void)
{
	char	*line;
	int		i;

	i = 0;
	g_f = (t_game_elem *)malloc(sizeof(*g_f));
	get_next_line(0, &line);
	g_f->x_o_team = (line[10] == '1') ? 'O' : 'X';
	free(line);
	while (get_next_line(0, &line))
	{
		g_f->y_board_max = ft_atoi(line + 8);
		while (ft_isdigit(*(line + 8 + i)))
			i++;
		g_f->x_board_max = ft_atoi(line + 8 + i);
		g_f->board = (char **)malloc(sizeof(char *) * g_f->y_board_max + 1);
		g_f->board[g_f->y_board_max] = 0;
		free(line);
		fill_board_with_lines();
		make_next_step();
		ft_printf("%d %d\n", g_cpu->y, g_cpu->x);
		clean_all_structs();
	}
	free(g_f);
	return (0);
}

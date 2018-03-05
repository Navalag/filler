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

void	fill_token_with_figure(int fd)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(fd, &line);
	dprintf(g_f->fd_test, "%s\n", line);
	// ft_printf("line: |%s|\n", line);
	g_f->y_token = ft_atoi(line + 6);
	g_f->x_token = ft_atoi(line + 8);
	// ft_printf("y_token = %d, x_token = %d\n", g_filler->y_token, g_filler->x_token);
	g_f->token = (char **)malloc(sizeof(char *) * g_f->y_token + 1);
	g_f->token[g_f->y_token] = 0;
	free(line);
	while (i < g_f->y_token)
	{
		get_next_line(fd, &line);
		g_f->token[i] = ft_strdup(line);
		dprintf(g_f->fd_test, "%s\n", line);
		// ft_printf("g_filler->token[%i]: |%s|\n", i, g_filler->token[i]);
		free(line);
		i++;
	}
}

void	fill_board_with_lines(int fd)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(fd, &line); // skip line
	dprintf(g_f->fd_test, "%s\n", line);
	free(line);
	while (i < g_f->y_max)
	{
		get_next_line(fd, &line);
		g_f->board[i] = ft_strdup(line + 4);
		dprintf(g_f->fd_test, "%s\n", line);
		// ft_printf("g_filler->board[%i]: |%s|\n", i, g_filler->board[i]);
		free(line);
		i++;
	}
	fill_token_with_figure(fd);
}

int		main(void)
{
	char	*line;
	int		i;

	i = 0;
	g_f = (t_game_elem *)malloc(sizeof(*g_f));
	g_f->fd_test = open("test_map.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	get_next_line(0, &line);
	g_f->x_o_team = (line[10] == '1') ? 'O' : 'X';
	// ft_printf("x_o_team = %c\n", g_filler->x_o_team); // test
	dprintf(g_f->fd_test, "%s\n", line);
	free(line);
	while (get_next_line(0, &line))
	{
		dprintf(g_f->fd_test, "%s\n", line);
		g_f->y_max = ft_atoi(line + 8);
		while (ft_isdigit(*(line + 8 + i)))
			i++;
		g_f->x_max = ft_atoi(line + 8 + i);
		// ft_printf("y_max = %d, x_max = %d\n", g_filler->y_max, g_filler->x_max); // test
		g_f->board = (char **)malloc(sizeof(char *) * g_f->y_max + 1);
		g_f->board[g_f->y_max] = 0;
		fill_board_with_lines(0);
		make_next_step();
		ft_printf("%d %d\n", g_cpu->y, g_cpu->x);
		free(line);
	}
	return (0);
}

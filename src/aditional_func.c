/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aditional_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:33:36 by agalavan          #+#    #+#             */
/*   Updated: 2018/03/06 10:33:38 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	insert_begin_val_to_struct(void)
{
	g_cpu->x = 0;
	g_cpu->y = 0;
	g_cpu->cpu = 10000;
}

void	clean_all_structs(void)
{
	int		i;

	i = -1;
	while (++i < g_f->y_board_max)
		free(g_f->board[i]);
	i = -1;
	while (++i < g_f->y_token_max)
		free(g_f->token[i]);
	free(g_f->board);
	free(g_f->token);
	free(g_cpu);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:15:51 by agalavan          #+#    #+#             */
/*   Updated: 2018/02/22 11:15:54 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libftprintf/inc/ft_printf.h"

typedef struct	s_board
{
	char	x_o_team;
	char	**board;
	char	**token;
	int		x_max;
	int		y_max;
	int		x_token;
	int		y_token;
}				t_game_elem;

t_game_elem		*g_filler;

#endif

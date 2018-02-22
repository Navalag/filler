/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:30:11 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/28 13:30:13 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** Description: Adds the element new at the beginning of the list.
**
** Param. #1 The address of a pointer to the first link of a list.
** Param. #2 The link to add at the beginning of the list.
**
** Return value: None.
** Libc functions: None.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

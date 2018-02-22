/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:46:29 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/28 13:46:31 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** Description: Iterates the list lst and applies the function f to each link.
**
** Param. #1 A pointer to the first link of a list.
** Param. #2 The address of a function to apply to each link of a list.
**
** Return value: None.
** Libc functions: None.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}

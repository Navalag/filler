/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:06:48 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/28 14:07:03 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** Description: Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the successive
** applications of f. If the allocation fails, the function
** returns NULL.
**
** Param. #1 A pointer’s to the first link of a list.
** Param. #2 The address of a function to apply to each link of a list.
**
** Return value The new list.
** Libc functions malloc(3), free(3).
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;

	if (!lst || !f)
		return (NULL);
	if (lst->next)
	{
		ret = ft_lstmap(lst->next, f);
		ft_lstadd(&ret, f(lst));
	}
	else
		ret = f(lst);
	return (ret);
}

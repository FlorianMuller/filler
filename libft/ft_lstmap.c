/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:46:41 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/25 17:02:02 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lcpy;
	t_list	*elem;

	if (lst == NULL || f == NULL)
		return (NULL);
	lcpy = f(lst);
	elem = lcpy;
	lst = lst->next;
	while (lst != NULL)
	{
		elem->next = f(lst);
		elem = elem->next;
		lst = lst->next;
	}
	return (lcpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:15:50 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/25 16:54:40 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	size_t	size_t_len;

	new = ft_memalloc(sizeof(size_t) + content_size + sizeof(t_list *));
	if (new == NULL)
		return (NULL);
	new->content_size = (size_t)ft_memalloc(sizeof(size_t));
	if ((void *)new->content_size == NULL)
		return (NULL);
	size_t_len = sizeof(size_t);
	ft_memcpy((void *)&(new->content_size), (void *)&content_size, size_t_len);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		if (new->content == NULL)
			return (NULL);
		ft_memcpy(new->content, content, content_size);
	}
	new->next = NULL;
	return (new);
}
/*
**ligne 26: pour eviter d'avoir une ligne de plus de 80 caractere
*/

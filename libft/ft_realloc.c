/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:49:53 by fmuller           #+#    #+#             */
/*   Updated: 2017/01/05 17:55:11 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	*ft_realloc(void *ptr, size_t size)
{
	char	*tmp;

	tmp = NULL;
	if (!(tmp = ft_memalloc(sizeof(char) * (size))))
		return (NULL);
	if (ptr != NULL)
		ft_strcpy(tmp, ptr);
	ft_memdel(&ptr);
	return (tmp);
}

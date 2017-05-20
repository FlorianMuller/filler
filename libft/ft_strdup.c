/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:40:19 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/18 17:46:50 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = ft_memalloc(ft_strlen(s1) + 1);
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, s1);
	return (copy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 13:52:38 by fmuller           #+#    #+#             */
/*   Updated: 2017/04/18 17:07:46 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strcountc(const char *str, char c)
{
	size_t	n;
	char	*s;

	if (str == NULL)
		return (0);
	if (c == '\0')
		return (1);
	n = 0;
	s = ft_strchr(str, c);
	while (s != NULL)
	{
		s = ft_strchr(s + 1, c);
		n++;
	}
	return (n);
}

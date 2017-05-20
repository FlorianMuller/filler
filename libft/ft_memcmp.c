/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:37:13 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/28 18:25:53 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
		i++;
	i = (i < n) ? i : i - 1;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

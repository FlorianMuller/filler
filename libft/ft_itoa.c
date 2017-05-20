/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:22:37 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/22 12:37:51 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	ft_setdiv(long n_copy, size_t *len)
{
	long	div;

	div = 1;
	*len = 1;
	while (n_copy / 10 > 0)
	{
		div = div * 10;
		n_copy = n_copy / 10;
		(*len)++;
	}
	return (div);
}

char			*ft_itoa(int n)
{
	char	*s;
	long	n_long;
	long	div;
	size_t	len;
	size_t	i;

	n_long = (n < 0) ? -(long)n : (long)n;
	div = ft_setdiv(n_long, &len);
	s = ft_memalloc((len + 1 + (n < 0)) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		s[i] = '-';
		i++;
	}
	while (i < len + (n < 0))
	{
		s[i] = n_long / div + '0';
		n_long = n_long % div;
		div = div / 10;
		i++;
	}
	return (s);
}

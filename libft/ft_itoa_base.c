/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:51:34 by fmuller           #+#    #+#             */
/*   Updated: 2017/02/02 14:33:15 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_get_len(long long n, int base)
{
	size_t				len;
	unsigned long long	n2;

	len = 0;
	n2 = (n < 0) ? -n : n;
	while (n2 > 0)
	{
		len++;
		n2 = n2 / base;
	}
	if (n == 0)
		len = 1;
	return ((base == 10 && n < 0) ? len + 1 : len);
}

char		*ft_itoa_base(long long n, int base)
{
	char				*str;
	unsigned long long	n2;
	size_t				len;

	n2 = (n < 0) ? -n : n;
	len = ft_get_len(n, base);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (base == 10 && n < 0)
		str[0] = '-';
	if (n2 == 0)
		str[0] = '0';
	while (n2 > 0)
	{
		if (n2 % base <= 9)
			str[len - 1] = '0' + n2 % base;
		else if (n2 % base <= 35)
			str[len - 1] = 'A' + (n2 % base - 10);
		else
			str[len - 1] = 'a' + (n2 % base - 36);
		n2 = n2 / base;
		len--;
	}
	return (str);
}

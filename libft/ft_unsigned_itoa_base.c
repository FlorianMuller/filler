/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:48:13 by fmuller           #+#    #+#             */
/*   Updated: 2017/04/18 17:08:29 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_get_len(unsigned long long n, int base)
{
	size_t				len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

char		*ft_unsigned_itoa_base(unsigned long long n, int base)
{
	char				*str;
	size_t				len;

	len = ft_get_len(n, base);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		if (n % base <= 9)
			str[len - 1] = '0' + n % base;
		else if (n % base <= 35)
			str[len - 1] = 'A' + (n % base - 10);
		else
			str[len - 1] = 'a' + (n % base - 36);
		n = n / base;
		len--;
	}
	return (str);
}

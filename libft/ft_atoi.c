/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:04:52 by fmuller           #+#    #+#             */
/*   Updated: 2017/01/20 16:39:06 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	n;
	size_t	start;
	long	nb;
	long	mult;

	n = 0;
	while (str[n] == ' ' || str[n] == '\t' || str[n] == '\n'
		|| str[n] == '\r' || str[n] == '\f' || str[n] == '\v')
		n++;
	if (str[n] == '-' || str[n] == '+')
		n++;
	start = n;
	while (str[n] >= '0' && str[n] <= '9')
		n++;
	nb = 0;
	mult = 1;
	while (n > start)
	{
		nb = nb + ((str[n - 1] - '0') * mult);
		mult = mult * 10;
		n--;
	}
	return ((start > 0 && str[start - 1] == '-') ? (int)(-nb) : (int)nb);
}

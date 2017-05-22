/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:10:22 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/22 18:10:53 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_power(long long nb, size_t power)
{
	long long res;

	res = 1;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

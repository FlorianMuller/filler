/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:49:40 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/22 18:01:23 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_sqrt(unsigned long long nb)
{
	unsigned long long a;
	unsigned long long sqrt_a;
	unsigned long long b;
	unsigned long long sqrt_b;

	a = 1;
	sqrt_a = 1;
	while (a < nb)
	{
		sqrt_b = sqrt_a;
		b = a;
		sqrt_a++;
		a = sqrt_a * sqrt_a;
	}
	if (a - nb <= nb - b)
		return (sqrt_a);
	return (sqrt_b);
}

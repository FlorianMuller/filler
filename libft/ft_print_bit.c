/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:09:00 by fmuller           #+#    #+#             */
/*   Updated: 2017/04/19 16:23:39 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bit(void *ptr, size_t n)
{
	size_t i;

	if (ptr != NULL)
	{
		i = n * 8;
		while (i > 0)
		{
			if (i % 8 == 0 && i != n * 8)
				ft_putchar('.');
			ft_putnbr(ft_read_bit(ptr, i));
			i--;
		}
	}
}

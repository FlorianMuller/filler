/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:21:15 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/29 12:45:17 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nb;

	nb = (n < 0) ? -(long)n : (long)n;
	if (n < 0)
		ft_putchar('-');
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else if (nb >= 10)
	{
		ft_putnbr((int)(nb / 10));
		ft_putchar((nb % 10) + '0');
	}
}

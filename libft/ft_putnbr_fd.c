/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:38:29 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/29 12:45:30 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (n < 0) ? -(long)n : (long)n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd((int)(nb / 10), fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
}

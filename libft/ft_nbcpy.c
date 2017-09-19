/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:21:56 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/11 18:17:54 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_nbcpy(int *tab, int lenght, ...)
{
	va_list	ap;
	int		n;
	int		nbr;

	n = 0;
	va_start(ap, lenght);
	while (n < lenght)
	{
		nbr = va_arg(ap, int);
		tab[n] = nbr;
		n++;
	}
	va_end(ap);
	return (tab);
}

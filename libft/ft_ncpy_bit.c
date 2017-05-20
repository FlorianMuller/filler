/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncpy_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:11:05 by fmuller           #+#    #+#             */
/*   Updated: 2017/04/14 15:17:22 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ncpy_bit(t_pbit src, t_pbit dst, size_t len)
{
	size_t	i;
	int		val;

	i = 0;
	while (i < len)
	{
		val = ft_read_bit(src.ptr, src.n + i);
		ft_set_bit(dst.ptr, val, dst.n + i);
		i++;
	}
}

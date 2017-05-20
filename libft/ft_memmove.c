/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:18:28 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/29 18:27:59 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	n;

	n = len - 1;
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	else if (src < dst)
	{
		while (n >= 0)
		{
			*((unsigned char *)dst + n) = *((unsigned char *)src + n);
			n--;
		}
	}
	return (dst);
}

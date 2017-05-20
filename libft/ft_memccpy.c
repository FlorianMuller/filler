/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:32:31 by fmuller           #+#    #+#             */
/*   Updated: 2017/04/18 17:03:08 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*pos_c;

	pos_c = ft_memchr(src, c, n);
	ft_memcpy(dst, src, (pos_c == NULL) ? n :
		(size_t)(pos_c - (char *)src + 1));
	return ((pos_c == NULL) ? NULL : dst + (pos_c - (char *)src + 1));
}

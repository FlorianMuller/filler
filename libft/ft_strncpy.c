/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:54:32 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/18 05:18:48 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t src_len;

	src_len = ft_strlen(src) + 1;
	if (len > src_len)
	{
		ft_memcpy(dst, src, src_len);
		ft_bzero((char *)dst + src_len, len - src_len);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

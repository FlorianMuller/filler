/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:00:39 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/21 16:14:04 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (size >= dst_len + 1)
	{
		ft_strncat(dst, src, size - (dst_len + 1));
		return (dst_len + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}

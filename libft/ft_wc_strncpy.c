/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc_strncpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:52:36 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/02 20:25:29 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wc_strncpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	size_t	src_len;

	src_len = ft_wcslen(src) + 1;
	if (len > src_len)
	{
		ft_memcpy(dst, src, src_len * sizeof(wchar_t));
		ft_bzero(dst + (src_len * sizeof(wchar_t)),
			(len - src_len) * sizeof(wchar_t));
	}
	else
		ft_memcpy(dst, src, len * sizeof(wchar_t));
	return (dst);
}

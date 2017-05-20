/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcs_conv_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:44:26 by fmuller           #+#    #+#             */
/*   Updated: 2017/04/19 16:25:37 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcs_conv_len(const wchar_t *s)
{
	int	i;
	int	len;

	if (s == NULL)
		return (0);
	i = 0;
	len = 0;
	while (s[i] != L'\0')
	{
		len += ft_wc_size(s[i]);
		i++;
	}
	return (len);
}

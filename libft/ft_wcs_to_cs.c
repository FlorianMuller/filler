/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcs_to_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:02:04 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/10 01:43:42 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcs_to_cs(char **dest, const wchar_t *src)
{
	int		i;
	int		j;

	if (src == NULL)
	{
		*dest = NULL;
		return (0);
	}
	i = 0;
	j = 0;
	if (!(*dest = ft_memalloc((ft_wcs_conv_len(src) + 1) * sizeof(char))))
		return (-1);
	while (src[i] != L'\0')
	{
		ft_wc_to_cs((*dest) + j, src[i]);
		j += ft_wc_size(src[i]);
		i++;
	}
	return (0);
}

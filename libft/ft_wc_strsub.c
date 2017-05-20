/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc_strsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:36:30 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/02 20:14:41 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wc_strsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*cp;

	if (s != NULL)
	{
		if (!(cp = ft_memalloc((len + 1) * sizeof(wchar_t))))
			return (NULL);
		ft_bzero(cp, (len + 1) * sizeof(wchar_t));
		ft_wc_strncpy(cp, s + start, len);
		return (cp);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:37:23 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/25 16:35:36 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cp;

	if (s != NULL)
	{
		cp = ft_strnew((len) * sizeof(char));
		if (cp == NULL)
			return (NULL);
		ft_strncpy(cp, s + start, len);
		return (cp);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:50:55 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/28 18:31:39 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	little_len;

	n = 0;
	little_len = ft_strlen(little);
	if (big == NULL)
		*((char *)big) = 'A';
	if (little[0] == '\0')
		return ((char *)big);
	while ((long)n < (long)(len - little_len + 1) && big[n] != '\0')
	{
		if (!ft_strncmp((char *)big + n, (char *)little, ft_strlen(little)))
			return ((char *)big + n);
		n++;
	}
	return (NULL);
}

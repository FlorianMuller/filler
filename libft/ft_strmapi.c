/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:35:13 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/25 16:24:06 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cp;
	unsigned int	n;

	if (s != NULL && f != NULL)
	{
		n = 0;
		cp = ft_strnew(ft_strlen(s));
		if (cp == NULL)
			return (NULL);
		while (s[n] != '\0')
		{
			cp[n] = f(n, s[n]);
			n++;
		}
		return (cp);
	}
	return (NULL);
}

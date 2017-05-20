/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:01:06 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/25 16:22:59 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cp;
	int		n;

	if (s != NULL && f != NULL)
	{
		n = 0;
		cp = ft_strnew(ft_strlen(s));
		if (cp == NULL)
			return (NULL);
		while (s[n] != '\0')
		{
			cp[n] = f(s[n]);
			n++;
		}
		return (cp);
	}
	return (NULL);
}

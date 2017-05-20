/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:24:27 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/25 16:34:58 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*cp;
	size_t	n;
	size_t	start;
	size_t	end;

	if (s == NULL)
		return (NULL);
	n = 0;
	while (ft_isspace(s[n]) && s[n] != '\0')
		n++;
	start = n;
	n = ft_strlen(s) - 1;
	while (ft_isspace(s[n]) && n > 0)
		n--;
	end = n;
	if (n == 0)
		cp = ft_strnew(0);
	else
		cp = ft_strnew(end - start + 1);
	if (cp == NULL)
		return (NULL);
	if (n != 0)
		ft_strncpy(cp, s + start, end - start + 1);
	return (cp);
}

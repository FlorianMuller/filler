/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:33:15 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/25 16:58:34 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbword(char *s, char c)
{
	size_t	n;
	int		nb;

	n = 0;
	nb = 0;
	while (s[n] != '\0')
	{
		while (s[n] == c)
			n++;
		if (s[n] != '\0')
			nb++;
		while (s[n] != c && s[n] != '\0')
			n++;
	}
	return (nb);
}

static	int	*ft_init_tabn(char *s, char c)
{
	int		*tabn;
	size_t	n;
	size_t	i;

	tabn = ft_memalloc((ft_nbword(s, c) + 1) * sizeof(int));
	if (tabn == NULL)
		return (NULL);
	n = 0;
	i = 0;
	while (s[n] != '\0')
	{
		while (s[n] == c)
			n++;
		if (s[n] != '\0')
		{
			tabn[i] = n;
			i++;
		}
		while (s[n] != c && s[n] != '\0')
			n++;
	}
	tabn[i] = -1;
	return (tabn);
}

static	int	lenw(char *s, char c, int n)
{
	int	len;

	len = 0;
	while (s[n] != c && s[n] != '\0')
	{
		len++;
		n++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		*tabn;
	size_t	i;

	if (s == NULL)
		return (NULL);
	tab = ft_memalloc((ft_nbword((char *)s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	if ((tabn = ft_init_tabn((char *)s, c)) == NULL)
		return (NULL);
	i = 0;
	while (tabn[i] != -1)
	{
		tab[i] = ft_memalloc((lenw((char *)s, c, tabn[i]) + 1) * sizeof(char));
		if (tab[i] == NULL)
			return (NULL);
		ft_memcpy(tab[i], s + tabn[i], lenw((char *)s, c, tabn[i]));
		i++;
	}
	tab[i] = ft_memalloc(1 * sizeof(char));
	if (tab[i] == NULL)
		return (NULL);
	tab[i] = 0;
	return (tab);
}

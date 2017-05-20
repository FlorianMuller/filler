/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:38:39 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/25 16:15:58 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	n;

	if (s != NULL && f != NULL)
	{
		n = 0;
		while (s[n] != '\0')
		{
			f(n, &s[n]);
			n++;
		}
	}
}

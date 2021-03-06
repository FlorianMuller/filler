/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:48:36 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/25 16:15:12 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	n;

	if (s != NULL && f != NULL)
	{
		n = 0;
		while (s[n] != '\0')
		{
			f(&s[n]);
			n++;
		}
	}
}

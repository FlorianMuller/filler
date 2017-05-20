/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:45:56 by fmuller           #+#    #+#             */
/*   Updated: 2017/04/18 17:09:18 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcslen(const wchar_t *s)
{
	int i;

	i = 0;
	while (s[i] != L'\0')
		i++;
	return (i);
}

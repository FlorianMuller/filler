/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:02:43 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/18 16:15:27 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ft_strncpy(s1 + s1_len, s2, (n > s2_len + 1) ? s2_len + 1 : n);
	ft_bzero(s1 + s1_len + ((n > s2_len) ? s2_len : n), 1);
	return (s1);
}

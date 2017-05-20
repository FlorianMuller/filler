/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:26:58 by fmuller           #+#    #+#             */
/*   Updated: 2016/11/29 11:29:23 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ptr_save;

	ptr = ft_strchr(s, c);
	ptr_save = ptr;
	if (c == '\0' || ptr == NULL)
		return (ptr);
	while ((ptr = ft_strchr(ptr + 1, c)) != NULL)
		ptr_save = ptr;
	return (ptr_save);
}

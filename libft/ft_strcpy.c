/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:12:32 by fmuller           #+#    #+#             */
/*   Updated: 2017/01/05 17:55:05 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "stdio.h"

char	*ft_strcpy(char *dst, const char *src)
{
	ft_strncpy(dst, src, ft_strlen(src) + 1);
	return (dst);
}

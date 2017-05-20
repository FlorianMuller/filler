/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 18:29:01 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/12 04:23:48 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Version 3.0: sans malloc
*/

char	*ft_str_insert(char **dst, char *src, size_t index, size_t dst_len)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	ft_memmove(*dst + index + src_len, *dst + index, dst_len - index);
	ft_memcpy(*dst + index, src, src_len);
	return (*dst);
}

/*
**Version 2.0:  moin secu et malloc
**char	*ft_str_insert(char **dst, char *src, size_t index, size_t dst_len)
**{
**	char	*s;
**
**	s = ft_strnew( dst_len + ft_strlen(src));
**	ft_memcpy(s, (*dst == NULL) ? "" : *dst, index);
**	ft_strcat(s, src);
**	// ft_strcat(s, (*dst == NULL) ? "" : *dst + index);
**	ft_memcpy(s, (*dst == NULL) ? "" : *dst + index, dst_len - index);
**	if (*dst != NULL)
**		ft_memdel((void **)dst);
**	*dst = s;
**	return (s);
**}
*/

/*
** Version 1.0: plus securisée et malloc
**
** char	*ft_str_insert(char **dst, char *src, size_t index)
** {
** 	char	*s;
** 	size_t	dst_len;
**
** 	dst_len = (*dst == NULL) ? 0 : ft_strlen(*dst);
** 	index = (index > dst_len) ? dst_len : index;
** 	s = ft_strnew(dst_len + ft_strlen(src));
** 	ft_strncpy(s, (*dst == NULL) ? "" : *dst, index);
** 	ft_strcat(s, src);
** 	ft_strcat(s, (*dst == NULL) ? "" : *dst + index);
** 	if (*dst != NULL)
** 		ft_memdel((void **)dst);
** 	*dst = s;
** 	return (s);
** }
*/

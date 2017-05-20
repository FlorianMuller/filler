/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:07:30 by fmuller           #+#    #+#             */
/*   Updated: 2017/01/09 15:52:35 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (s1 != NULL && s2 != NULL)
	{
		join = ft_strnew((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (join == NULL)
			return (NULL);
		ft_strcpy(join, s1);
		ft_strcat(join, s2);
		return (join);
	}
	return (NULL);
}

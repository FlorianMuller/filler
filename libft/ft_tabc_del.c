/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabc_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:26:29 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/10 20:50:09 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabc_del(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i])
	{
		ft_strdel((*tab) + i);
		(*tab)[i] = NULL;
		i++;
	}
	if (*tab != NULL)
	{
		ft_memdel((void **)tab);
		*tab = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc_to_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:55:07 by fmuller           #+#    #+#             */
/*   Updated: 2017/04/18 18:33:50 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_prout(int max_k, t_pbit *p_src, size_t *len)
{
	if (max_k == 1)
	{
		p_src->n = 1;
		*len = 7;
		return (0);
	}
	else if (max_k == 2)
	{
		p_src->n = 7;
		*len = 5;
		return (192);
	}
	else if (max_k == 3)
	{
		p_src->n = 13;
		*len = 4;
		return (224);
	}
	else
	{
		p_src->n = 19;
		*len = 3;
		return (240);
	}
}

static int		ft_set_base(int k, int max_k, t_pbit *p_src, size_t *len)
{
	if (k == max_k)
		return (ft_prout(max_k, p_src, len));
	else
	{
		p_src->n -= 6;
		*len = 6;
		return (128);
	}
}

void			ft_wc_to_cs(char *dest, wchar_t src)
{
	int		j;
	t_pbit	p_dest;
	t_pbit	p_src;
	size_t	len;
	int		size;

	j = 0;
	size = ft_wc_size(src);
	ft_init_pbit(&p_dest, (void *)dest, 1);
	ft_init_pbit(&p_src, (void *)&src, 1);
	while (j < size)
	{
		dest[j] = ft_set_base(size - j, size, &p_src, &len);
		ft_ncpy_bit(p_src, p_dest, len);
		j++;
		p_dest.ptr++;
	}
}

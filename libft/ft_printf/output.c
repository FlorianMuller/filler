/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:53:35 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:44:15 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_str_insert_c(char **dst, char c, size_t index, size_t dst_len)
{
	ft_memmove(*dst + index + 1, *dst + index, dst_len - index);
	(*dst)[index] = c;
	return (*dst);
}

void	ft_putchar_output(char c, t_all *all, size_t index)
{
	if (all->write)
		ft_str_insert_c(&(all->output), c, index, all->len);
	all->rett++;
	all->len++;
}

void	ft_putchar_endoutput(char c, t_all *all)
{
	ft_putchar_output(c, all, (all->output == NULL) ? 0 : all->len);
}

void	ft_putstr_output(char *src, t_all *all, size_t index)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (all->write)
		ft_str_insert(&(all->output), src, index, all->len);
	all->rett += src_len;
	all->len += src_len;
}

void	ft_putstr_endoutput(char *src, t_all *all)
{
	ft_putstr_output(src, all, (all->output == NULL) ? 0 : all->len);
}

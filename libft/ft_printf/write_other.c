/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 00:37:54 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:31 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include <inttypes.h>

void	ft_write_n(t_param *param, t_all *all)
{
	if (!ft_strcmp(param->lenght, "hh"))
		*((char *)(va_arg(all->ap, int *))) = all->rett;
	else if (!ft_strcmp(param->lenght, "h"))
		*((short *)(va_arg(all->ap, int *))) = all->rett;
	else if (!ft_strcmp(param->lenght, "l"))
		*(va_arg(all->ap, long *)) = all->rett;
	else if (!ft_strcmp(param->lenght, "ll"))
		*(va_arg(all->ap, long long *)) = all->rett;
	else if (!ft_strcmp(param->lenght, "j"))
		*(va_arg(all->ap, intmax_t *)) = all->rett;
	else if (!ft_strcmp(param->lenght, "z"))
		*(va_arg(all->ap, size_t *)) = all->rett;
	else if (!ft_strcmp(param->lenght, "L"))
		*(va_arg(all->ap, long double *)) = all->rett;
	else
		*(va_arg(all->ap, int *)) = all->rett;
}

int		ft_write_pointer(t_param *param, t_all *all)
{
	char	*str;

	if ((str = ft_itoa_base((long)va_arg(all->ap, void *), 16)) == NULL)
		return (-1);
	ft_striter(str, &ft_tolower_pchar);
	ft_write_all(param, str, all);
	ft_memdel((void **)&str);
	return (0);
}

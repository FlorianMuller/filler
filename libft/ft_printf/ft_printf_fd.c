/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:23:36 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:51:41 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

int				ft_printf_fd(int fd, const char *format, ...)
{
	t_all	all;
	int		ret;

	ft_init_all_printf(&all);
	va_start(all.ap, format);
	if (ft_init_param_list(&all.param_list, all.ap, format))
		return (-1);
	va_end(all.ap);
	va_start(all.ap, format);
	while (!all.end || !all.write)
	{
		if ((ret = ft_(&all, format)) == -1)
			return (ft_free_all(&all));
		else
		{
			va_end(all.ap);
			va_start(all.ap, format);
			if (ft_truc(&all, ret) == -1)
				return (ft_free_all(&all));
		}
	}
	write(fd, all.output, all.len);
	ft_free_all(&all);
	return (all.rett);
}

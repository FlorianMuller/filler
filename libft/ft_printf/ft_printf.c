/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:45:06 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/11 04:43:46 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

int			ft_free_all(t_all *all)
{
	if (all->output != NULL)
		ft_memdel((void **)&(all->output));
	ft_memdel((void **)&(all->param_list));
	return (-1);
}

static int	ft_percent(t_all *all, char *str, int *wanted_param)
{
	ft_set_nbr_param(str, wanted_param, all);
	if ((*wanted_param) != -1 && *wanted_param != all->current_param)
	{
		if (*wanted_param > all->current_param)
			ft_find_param(*wanted_param, all);
		else
		{
			while (str[all->i] != '%')
				(all->i)--;
			return (*wanted_param);
		}
	}
	if (ft_read((char *)str, all))
		return (-1);
	all->current_param++;
	return (-10);
}

int			ft_(t_all *all, const char *str)
{
	int	wanted_param;
	int	ret;

	while (str[all->i] != '\0')
	{
		if (str[all->i] == '%')
		{
			if ((ret = ft_percent(all, (char *)str, &wanted_param)) != -10)
				return (ret);
		}
		else if (str[all->i] == '{')
		{
			if (ft_color(all, str) == -1)
				return (-1);
		}
		else
			ft_putchar_endoutput(str[all->i], all);
		all->i++;
	}
	all->end = 1;
	return (0);
}

int			ft_truc(t_all *all, int ret)
{
	all->current_param = 1;
	if (all->end && !all->write)
	{
		if (ft_reset_all_printf(all) == NULL)
			return (-1);
	}
	else if (!all->end)
		ft_find_param(ret, all);
	return (0);
}

int			ft_printf(const char *format, ...)
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
	write(1, all.output, all.len);
	ft_free_all(&all);
	return (all.rett);
}

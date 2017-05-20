/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:01:25 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:25 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

static t_param	ft_init_param(void)
{
	t_param param;

	ft_bzero(param.flag_lst, 7 * sizeof(int));
	param.flag_lst[6] = -1;
	param.width = -1;
	param.precision = -1;
	ft_bzero(param.lenght, 3 * sizeof(char));
	param.type = '\0';
	param.len = 0;
	param.start = 0;
	param.default_value = -1;
	return (param);
}

static int		ft_choose_type(t_param *param, t_all *all)
{
	if (param->type == 'S' || (param->type == 's' &&
		!ft_strcmp(param->lenght, "l")))
		return (ft_write_big_s(param, all));
	else if (param->type == 's')
		return (ft_write_s(param, all));
	else if (ft_is_nbr(param->type))
		return (ft_write_nbr(param, all));
	else if (param->type == 'C' || (param->type == 'c' &&
		!ft_strcmp(param->lenght, "l")))
		return (ft_write_big_c(param, all));
	else if (param->type == 'c')
		ft_write_c(param, all);
	else if (param->type == 'p')
		return (ft_write_pointer(param, all));
	else if (param->type == '%')
		ft_write_percent(param, all);
	else if (param->type == 'n')
		ft_write_n(param, all);
	return (0);
}

int				ft_read(char *str, t_all *all)
{
	size_t	j;
	t_param param;

	param = ft_init_param();
	j = all->i + 1;
	j = j + ft_set_flag(str + j, &param);
	j = j + ft_set_width(str + j, &param, all->ap, all->param_list);
	j = j + ft_set_precision(str + j, &param, all->ap, all->param_list);
	j = j + ft_set_type(str + j, &param);
	if (param.default_value == '\0')
	{
		all->i = j - 1;
		return (0);
	}
	all->i = j;
	return (ft_choose_type(&param, all));
}

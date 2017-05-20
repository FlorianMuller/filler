/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:21:34 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:27 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

static void	ft_set_width_next(char *str, t_param *param, int *param_list,
	size_t *i)
{
	param->width = param_list[ft_atoi(str + 1) - 1];
	(*i)++;
}

size_t		ft_set_width(char *str, t_param *param, va_list ap, int *param_list)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i > 0)
		param->width = ft_atoi(str);
	else if (str[0] == '*')
	{
		i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == '$')
			ft_set_width_next(str, param, param_list, &i);
		else
			param->width = va_arg(ap, int);
		if (param->width < 0)
		{
			param->width *= -1;
			param->flag_lst[0] = 1;
		}
	}
	return (i);
}

static int	ft_set_precision_next(char *str, t_param *param, size_t *i)
{
	(*i)++;
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (*i > 1)
	{
		param->precision = ft_atoi(str + 1);
		return (1);
	}
	else if (str[1] != '*' && *i == 1)
	{
		param->precision = 0;
		return (1);
	}
	return (0);
}

size_t		ft_set_precision(char *str, t_param *param, va_list ap,
	int *param_list)
{
	size_t i;

	i = 0;
	if (str[i] == '.')
	{
		if (ft_set_precision_next(str, param, &i))
			return (i);
		else if (str[1] == '*')
		{
			i++;
			while (ft_isdigit(str[i]))
				i++;
			if (str[i] == '$')
			{
				param->precision = param_list[ft_atoi(str + 2) - 1];
				i++;
			}
			else
				param->precision = va_arg(ap, int);
			if (param->precision < 0)
				param->precision = -1;
		}
	}
	return (i);
}

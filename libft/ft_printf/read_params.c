/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:11:09 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:26 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

/*
**0: -|1: +|2: ' '|3: 0|4: #|5: '
*/

void	ft_set_nbr_param(const char *str, int *wanted_param, t_all *all)
{
	size_t	j;

	j = 1;
	*wanted_param = -1;
	while (ft_isdigit(str[all->i + j]))
		j++;
	if (str[all->i + j] == '$' && j != 1)
	{
		*wanted_param = ft_atoi(str + all->i + 1);
		all->i += j;
	}
}

size_t	ft_set_flag(char *str, t_param *param)
{
	size_t	i;
	size_t	j;
	char	*lst;

	i = 0;
	lst = ft_strdup("-+ 0#'");
	while (ft_is_flags(str[i]))
	{
		j = 0;
		while (lst[j])
		{
			if (str[i] == lst[j])
				param->flag_lst[j] = 1;
			j++;
		}
		i++;
	}
	if (param->flag_lst[0] == 1)
		param->flag_lst[3] = 0;
	ft_memdel((void **)&lst);
	return (i);
}

size_t	ft_set_type(char *str, t_param *param)
{
	size_t	i;

	i = 0;
	while (ft_is_lenght(str[i]) && i < 2)
	{
		param->lenght[i] = str[i];
		i++;
	}
	if (ft_is_type(str[i]))
		param->type = str[i];
	else
	{
		param->type = 'c';
		param->default_value = str[i];
	}
	if (param->precision != -1 && ft_is_nbr(param->type))
		param->flag_lst[3] = 0;
	if (param->type == 'D' || param->type == 'O' || param->type == 'U' ||
		param->type == 'B')
	{
		param->lenght[0] = 'l';
		// param->lenght[1] = '\0';
	}
	return (i);
}

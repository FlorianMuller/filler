/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:47:09 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:24 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

static void		ft_find_dollar(size_t *nbr_max, size_t *nbr, const char *str)
{
	size_t	j;

	j = 1;
	while (ft_isdigit(str[j]))
		j++;
	if (j > 0 && str[j] == '$')
	{
		if (str[0] == '*')
		{
			if ((int)*nbr_max < ft_atoi(str + 1))
				*nbr_max = ft_atoi(str + 1);
		}
		else
			*nbr = ft_atoi(str + 1);
	}
	else
		(*nbr)++;
	if (*nbr_max < *nbr)
		*nbr_max = *nbr;
}

static size_t	ft_count_param(const char *str)
{
	size_t	nbr_max;
	size_t	nbr;
	size_t	i;
	size_t	j;

	nbr_max = 0;
	nbr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '%')
				ft_find_dollar(&nbr_max, &nbr, str + i);
			j = 1;
			while (!ft_is_type(str[i + j]))
			{
				if (str[i + j] == '*')
					ft_find_dollar(&nbr_max, &nbr, str + i + j);
				j++;
			}
		}
		i++;
	}
	return (nbr_max);
}

void			ft_find_param(int wanted_param, t_all *all)
{
	while (all->current_param < wanted_param)
	{
		va_arg(all->ap, void *);
		all->current_param++;
	}
}

int				ft_init_param_list(int **param_list, va_list ap,
	const char *str)
{
	int i;
	int nbr_param;

	i = 0;
	nbr_param = ft_count_param(str);
	if (((*param_list) = ft_memalloc(nbr_param * sizeof(int))) == NULL &&
		nbr_param != 0)
		return (-1);
	while (i < nbr_param)
	{
		(*param_list)[i] = va_arg(ap, unsigned int);
		i++;
	}
	return (0);
}

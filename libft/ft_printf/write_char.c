/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 00:59:21 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:30 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include <stdlib.h>

int		ft_write_big_c(t_param *param, t_all *all)
{
	char	str[5];
	wchar_t	wchar;

	bzero(str, sizeof(str));
	wchar = va_arg(all->ap, wchar_t);
	if (MB_CUR_MAX == 1)
	{
		if (wchar <= 255)
			str[0] = (char)wchar;
		else
		{
			return (-1);
		}
	}
	else
		ft_wc_to_cs(str, wchar);
	ft_write_all(param, str, all);
	return (0);
}

void	ft_write_c(t_param *param, t_all *all)
{
	char	str[2];

	bzero(str, sizeof(str));
	if (param->default_value != -1)
		str[0] = param->default_value;
	else
		str[0] = (unsigned char)va_arg(all->ap, int);
	ft_write_all(param, str, all);
}

void	ft_write_percent(t_param *param, t_all *all)
{
	char	str[2];

	bzero(str, 2);
	str[0] = '%';
	ft_write_all(param, str, all);
}

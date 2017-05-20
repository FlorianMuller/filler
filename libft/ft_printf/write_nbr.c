/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:14:42 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:30 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include <inttypes.h>

/*
**0: -|1: +|2: ' '|3: 0|4: #|5: '
*/

static int	ft_set_base(t_param param)
{
	if (param.type == 'x' || param.type == 'X')
		return (16);
	else if (param.type == 'o' || param.type == 'O')
		return (8);
	else if (param.type == 'b' || param.type == 'B')
		return (2);
	else
		return (10);
}

static void	ft_type_selector_next(t_param param, va_list ap, char **str,
	int base)
{
	if (!ft_strcmp(param.lenght, "ll"))
		if (param.type == 'd' || param.type == 'D' || param.type == 'i')
			*str = ft_itoa_base(va_arg(ap, long long), base);
		else
			*str = ft_unsigned_itoa_base(va_arg(ap, unsigned long long), base);
	else if (!ft_strcmp(param.lenght, "j"))
		if (param.type == 'd' || param.type == 'D' || param.type == 'i')
			*str = ft_itoa_base(va_arg(ap, intmax_t), base);
		else
			*str = ft_unsigned_itoa_base(va_arg(ap, intmax_t), base);
	else if (!ft_strcmp(param.lenght, "z"))
		if (param.type == 'd' || param.type == 'D' || param.type == 'i')
			*str = ft_itoa_base(va_arg(ap, size_t), base);
		else
			*str = ft_unsigned_itoa_base(va_arg(ap, size_t), base);
	else if (!ft_strcmp(param.lenght, "L"))
		*str = ft_itoa_base(va_arg(ap, long double), base);
	else
	{
		if (param.type == 'd' || param.type == 'D' || param.type == 'i')
			*str = ft_itoa_base(va_arg(ap, int), base);
		else
			*str = ft_unsigned_itoa_base(va_arg(ap, unsigned int), base);
	}
}

static char	*ft_type_selector(t_param param, va_list ap, char **str)
{
	int	base;

	base = ft_set_base(param);
	if (!ft_strcmp(param.lenght, "hh"))
		if (param.type == 'd' || param.type == 'D' || param.type == 'i')
			*str = ft_itoa_base((char)(va_arg(ap, int)), base);
		else
			*str = ft_unsigned_itoa_base((unsigned char)
				(va_arg(ap, unsigned int)), base);
	else if (!ft_strcmp(param.lenght, "h"))
		if (param.type == 'd' || param.type == 'D' || param.type == 'i')
			*str = ft_itoa_base((short)(va_arg(ap, int)), base);
		else
			*str = ft_unsigned_itoa_base((unsigned short)
				(va_arg(ap, unsigned int)), base);
	else if (!ft_strcmp(param.lenght, "l"))
		if (param.type == 'd' || param.type == 'D' || param.type == 'i')
			*str = ft_itoa_base(va_arg(ap, long), base);
		else
			*str = ft_unsigned_itoa_base((unsigned long)
				(va_arg(ap, unsigned long)), base);
	else
		ft_type_selector_next(param, ap, str, base);
	return (*str);
}

void		ft_tolower_pchar(char *c)
{
	*c = (char)ft_tolower((int)*c);
}

int			ft_write_nbr(t_param *param, t_all *all)
{
	char	*str;

	if (ft_type_selector(*param, all->ap, &str) == NULL)
		return (-1);
	if (param->type == 'x')
		ft_striter(str, &ft_tolower_pchar);
	ft_write_all(param, str, all);
	ft_memdel((void **)&str);
	return (0);
}

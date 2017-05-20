/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:42:20 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:28 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**0: -|1: +|2: ' '|3: 0|4: #|5: '
*/

static void	ft_write_plus(t_param *param, t_all *all)
{
	if (param->flag_lst[1] == 1)
		ft_putchar_endoutput('+', all);
	else if (param->flag_lst[2] == 1)
		ft_putchar_endoutput(' ', all);
}

static void	ft_write_ashtag(t_param *param, t_all *all, char *str)
{
	if ((param->type == 'o' || param->type == 'O') && param->precision <=
		(int)ft_strlen(str) && (str[0] != '0' || param->precision == 0))
		ft_putchar_endoutput('0', all);
	else if ((param->type == 'x' && str[0] != '0') || param->type == 'p' ||
		param->type == 'b' || param->type == 'B')
		ft_putstr_endoutput("0x", all);
	else if ((param->type == 'X') && str[0] != '0')
		ft_putstr_endoutput("0X", all);
}

static void	ft_write_precision(t_param *param, t_all *all, char *str)
{
	int	n;
	int	precision_len;

	n = 0;
	precision_len = param->precision - (int)ft_strlen(str);
	while (n < precision_len)
	{
		ft_putchar_endoutput('0', all);
		n++;
	}
}

static void	ft_write_width(t_param *param, t_all *all, int output_len)
{
	int		width_len;
	char	c;
	int		n;

	n = 0;
	c = (param->flag_lst[3]) ? '0' : ' ';
	width_len = param->width - (all->len - output_len);
	if (width_len > 0)
	{
		while (n < width_len)
		{
			ft_putchar_output(c, all, param->start);
			n++;
		}
	}
}

void		ft_write_all(t_param *param, char *str, t_all *all)
{
	int	output_len;

	output_len = all->len;
	if (param->flag_lst[0] == 0 && param->flag_lst[3] == 0)
		param->start = all->len;
	if ((param->type == 'D' || param->type == 'd' || param->type == 'i') &&
		str[0] != '-')
		ft_write_plus(param, all);
	else if (param->flag_lst[4] == 1 || param->type == 'p')
		ft_write_ashtag(param, all, str);
	if (str[0] == '-' && ft_is_nbr(param->type))
	{
		ft_putchar_endoutput(str[0], all);
		str++;
	}
	if ((ft_is_nbr(param->type) || param->type == 'p') &&
		param->precision != -1)
		ft_write_precision(param, all, str);
	ft_write_string(param, str, all);
	if (param->width != -1)
		ft_write_width(param, all, output_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_all2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 01:53:09 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:29 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**0: -|1: +|2: ' '|3: 0|4: #|5: '
*/

void	ft_apostrophe(char *str, t_all *all)
{
	int	n;
	int	str_len;

	str_len = ft_strlen(str);
	n = str_len;
	while (n > 0)
	{
		if (!(n % 3) && n != 0 && n != str_len)
			ft_putchar_endoutput(',', all);
		ft_putchar_endoutput(str[str_len - n], all);
		n--;
	}
}

void	ft_write_string(t_param *param, char *str, t_all *all)
{
	if (param->flag_lst[0] == 0 && param->flag_lst[3] == 1)
		param->start = all->len;
	if (param->flag_lst[5] == 1 && (param->type == 'd' || param->type == 'D' ||
		param->type == 'i' || param->type == 'o' || param->type == 'O' ||
		param->type == 'p'))
		ft_apostrophe(str, all);
	else if (!((param->precision == 0 && str[0] == '0') &&
		(ft_is_nbr(param->type) || param->type == 'p')))
	{
		if ((param->type == 'c' || param->type == 'C') && str[0] == 0)
			ft_putchar_endoutput(str[0], all);
		else
			ft_putstr_endoutput(str, all);
	}
	if (param->flag_lst[0] == 1)
		param->start = all->len;
}

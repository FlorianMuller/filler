/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:29:20 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:35 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

/*
**0: -|1: +|2: ' '|3: 0|4: #|5: '
*/

static char		*ft_s_precision(char **str, int precision, int *need_free)
{
	char *str2;

	str2 = *str;
	*str = ft_strsub(*str, 0, precision);
	if (*need_free)
		ft_memdel((void **)&str2);
	*need_free = 1;
	return (*str);
}

static wchar_t	*ft_big_s_precision(wchar_t **wc_str, int precision)
{
	int	new_len;
	int	i;

	i = 0;
	new_len = 0;
	while (precision > 0)
	{
		precision -= ft_wc_size((*wc_str)[i]);
		if (precision >= 0)
			new_len++;
		i++;
	}
	*wc_str = ft_wc_strsub(*wc_str, 0, new_len);
	return (*wc_str);
}

static size_t	ft_wc_strlen_conv(wchar_t *s)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != L'\0')
	{
		len += ft_wc_size(s[i]);
		i++;
	}
	return (len);
}

int				ft_write_big_s(t_param *param, t_all *all)
{
	wchar_t	*wc_str;
	char	*str;
	int		need_free;

	wc_str = va_arg(all->ap, wchar_t *);
	if (wc_str == NULL)
	{
		str = ft_strdup("(null)");
		need_free = 1;
		if (param->precision != -1 && (size_t)(param->precision)
			< ft_strlen(str))
			ft_s_precision(&str, param->precision, &need_free);
	}
	else
	{
		if (param->precision != -1 && (size_t)(param->precision) <
			ft_wc_strlen_conv(wc_str))
			if (ft_big_s_precision(&wc_str, param->precision) == NULL)
				return (-1);
		if (ft_wcs_to_cs(&str, wc_str) == -1)
			return (-1);
	}
	ft_write_all(param, str, all);
	ft_memdel((void **)&str);
	return (0);
}

int				ft_write_s(t_param *param, t_all *all)
{
	char	*str;
	int		need_free;

	need_free = 0;
	str = va_arg(all->ap, char *);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		need_free = 1;
	}
	if (param->precision != -1 && (size_t)(param->precision) < ft_strlen(str))
		if (ft_s_precision(&str, param->precision, &need_free) == NULL)
			return (-1);
	ft_write_all(param, str, all);
	if (need_free)
		ft_memdel((void **)&str);
	return (0);
}

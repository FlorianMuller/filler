/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:43:10 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:15 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**usage:	{attribute,foreground,background}
**			{attribute,foreground}
**			{foreground,background}
**			{foreground}
**			{attribute}
**
**attribute: 		reset, bright, dark, italic, underline, reverse
**color:			black, red, green, yellow, blue, magenta, cyan, white
*/

#include "../libft.h"

int		ft_change_color(t_all *all)
{
	char	str[14];
	char	*str_tmp;

	ft_bzero(str, 14);
	ft_strcpy(str, "\x1B[");
	ft_strcat(str, all->color_status.attribute);
	ft_strcat(str, ";");
	if ((str_tmp = ft_itoa(ft_atoi(all->color_status.forground) + 30 +
		all->color_status.is_fg_light)) == NULL)
		return (-1);
	ft_strcat(str, str_tmp);
	ft_memdel((void **)&str_tmp);
	ft_strcat(str, ";");
	if ((str_tmp = ft_itoa(ft_atoi(all->color_status.background) + 40 +
		all->color_status.is_bg_light)) == NULL)
		return (-1);
	ft_strcat(str, str_tmp);
	ft_memdel((void **)&str_tmp);
	ft_strcat(str, "m");
	ft_putstr_endoutput(str, all);
	all->rett -= 10;
	return (0);
}

int		ft_reset_color(t_all *all)
{
	all->color_status = ft_init_status();
	if (ft_change_color(all) == -1)
		return (-1);
	return (0);
}

void	ft_reset_new_color_status(t_color *color_status)
{
	color_status->new_attribute[0] = '\0';
	color_status->new_forground[0] = '\0';
	color_status->new_background[0] = '\0';
	color_status->new_is_fg_light = 0;
	color_status->new_is_bg_light = 0;
	color_status->dontchange = 0;
}

int		ft_free_key_word(t_word *key_word)
{
	ft_tabc_del(&(key_word->color_word));
	ft_tabc_del(&(key_word->color_value));
	ft_tabc_del(&(key_word->attribute_word));
	ft_tabc_del(&(key_word->attribute_value));
	return (1);
}

int		ft_color(t_all *all, const char *str)
{
	int ret;
	int	j;
	int	dontchange;

	j = all->i;
	dontchange = (str[all->i + 1] == '{') ? 1 : 0;
	all->i += (str[all->i + 1] == '{') ? 2 : 1;
	if ((ret = ft_read_color((char *)str, all)) == -1)
		return (-1);
	else if (ret == 0 && !dontchange)
	{
		ft_change_status(&(all->color_status));
		if (ft_change_color(all) == -1)
			return (-1);
	}
	else
	{
		ft_reset_new_color_status(&(all->color_status));
		ft_putchar_endoutput('{', all);
		all->i = j + ((ret == 0) ? 1 : 0);
	}
	return (0);
}

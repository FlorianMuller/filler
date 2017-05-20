/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 00:18:21 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:20 by fmuller          ###   ########.fr       */
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

static int	ft_check_attribute(char *str, t_word key_word, t_color *color_status
	, int *i)
{
	int		n;
	size_t	len;

	n = 0;
	len = ft_set_len(str + *i);
	while (key_word.attribute_word[n] && ft_strncmp(str + *i,
		key_word.attribute_word[n], len))
		n++;
	if (key_word.attribute_word[n])
	{
		if (!(color_status->new_attribute[0]))
			color_status->new_attribute[0] = key_word.attribute_value[n][0];
		else
			return (1);
		return (0);
	}
	return (1);
}

static int	ft_set_color(char *str, t_word key_word, t_color *color_status
	, int *i)
{
	int		n;
	size_t	len;

	n = 0;
	len = ft_set_len(str + *i);
	while (key_word.color_word[n] && ft_strncmp(str + *i, key_word.color_word[n]
		, len))
		n++;
	if (key_word.color_word[n])
	{
		if (color_status->new_forground[0] &&
			!(color_status->new_background[0]))
			color_status->new_background[0] = key_word.color_value[n][0];
		else if (!(color_status->new_forground[0]))
			color_status->new_forground[0] = key_word.color_value[n][0];
		else
			return (1);
		return (0);
	}
	return (ft_check_attribute(str, key_word, color_status, i));
}

void		ft_change_status(t_color *color_status)
{
	if (color_status->new_attribute[0])
		color_status->attribute[0] = color_status->new_attribute[0];
	if (color_status->new_forground[0])
	{
		color_status->forground[0] = color_status->new_forground[0];
		color_status->is_fg_light = color_status->new_is_fg_light;
	}
	if (color_status->new_background[0])
	{
		color_status->background[0] = color_status->new_background[0];
		color_status->is_bg_light = color_status->new_is_bg_light;
	}
	ft_reset_new_color_status(color_status);
}

static int	ft_eoc(t_all *all)
{
	all->i += 3;
	ft_reset_color(all);
	return (0);
}

int			ft_read_color(char *str, t_all *all)
{
	size_t	nb_arg;
	size_t	n;
	t_word	key_word;

	n = 0;
	if ((nb_arg = ft_set_argument(str + all->i)) > 3)
		return (1);
	if (nb_arg == 1 && !ft_strncmp(str + all->i, "eoc}", 4))
		return (ft_eoc(all));
	if (ft_init_key_word(&key_word) == -1)
		return (-1);
	while (n < nb_arg)
	{
		ft_set_is_light(str, &(all->i), &(all->color_status));
		if (ft_set_color(str, key_word, &(all->color_status), &(all->i)))
			return (ft_free_key_word(&key_word));
		all->i += ft_set_len(str + all->i) + ((n == nb_arg - 1) ? 0 : 1);
		n++;
	}
	ft_free_key_word(&key_word);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:43:10 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/17 18:36:18 by fmuller          ###   ########.fr       */
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

t_color	ft_init_status(void)
{
	t_color status;

	ft_strcpy(status.attribute, "0");
	ft_strcpy(status.background, "0");
	ft_strcpy(status.forground, "7");
	ft_bzero(status.new_attribute, 2);
	ft_bzero(status.new_forground, 2);
	ft_bzero(status.new_background, 2);
	status.is_fg_light = 0;
	status.is_bg_light = 0;
	status.new_is_fg_light = 0;
	status.new_is_bg_light = 0;
	status.dontchange = 0;
	return (status);
}

int		ft_init_key_word(t_word *key_word)
{
	char	color_word[47];
	char	color_value[16];
	char	attribute_word[43];
	char	attribute_value[12];

	ft_strncpy(color_word, "black red green yellow blue magenta cyan white",
		47);
	ft_strncpy(color_value, "0 1 2 3 4 5 6 7", 16);
	ft_strncpy(attribute_word, "reset bright dark italic underline reverse",
		43);
	ft_strncpy(attribute_value, "0 1 2 3 4 7", 12);
	key_word->color_word = ft_strsplit(color_word, ' ');
	key_word->color_value = ft_strsplit(color_value, ' ');
	key_word->attribute_word = ft_strsplit(attribute_word, ' ');
	key_word->attribute_value = ft_strsplit(attribute_value, ' ');
	if (key_word->color_word == NULL || key_word->color_value == NULL ||
		key_word->attribute_word == NULL || key_word->attribute_value == NULL)
		return (-1);
	return (0);
}

size_t	ft_set_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '}' && str[i] != ',' && str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_set_argument(char *str)
{
	size_t	i;
	size_t	nb_arg;

	i = 0;
	nb_arg = 1;
	while (str[i] != '}' && str[i] != '\0')
	{
		if (str[i] == ',')
			nb_arg++;
		i++;
	}
	return (nb_arg);
}

void	ft_set_is_light(char *str, int *i, t_color *color_status)
{
	if (str[*i] == 'l')
	{
		if ((color_status->new_forground)[0])
			color_status->new_is_bg_light = 60;
		else
			color_status->new_is_fg_light = 60;
		(*i)++;
	}
}

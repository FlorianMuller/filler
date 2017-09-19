/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 03:19:34 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/12 20:34:46 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "back_to_the_filler.h"

int		ft_get_name(char *s, char **p)
{
	int	i;
	int	len;

	i = ft_strlen(s);
	len = 0;
	while (s[i] != '/')
		i--;
	while (s[i + len] != '.')
		len++;
	if (!(*p = ft_strnew(len - 1)))
		return (2);
	ft_strncpy(*p, s + i + 1, len - 1);
	return (0);
}

int		ft_get_players(t_env *env)
{
	char	*s;
	int		ret;

	env->p1 = NULL;
	env->p2 = NULL;
	while ((!env->p1 || !env->p2) && (ret = get_next_line(env->fd, &s) == 1))
	{
		if (ft_error_test(s))
			return (1);
		if (!ft_strncmp(s, "$$$", 3))
		{
			if (!ft_strncmp(s + 10, "1", 1))
			{
				if ((ft_get_name(s, &(env->p1))))
					return (2);
			}
			else
			{
				if ((ft_get_name(s, &(env->p2))))
					return (2);
			}
		}
		ft_strdel(&s);
	}
	return (((ret == -1) ? 3 : 0));
}

int		ft_get_map_size(t_env *env)
{
	char	*s;
	int		i;

	i = 0;
	if ((get_next_line(env->fd, &s)) == -1)
		return (3);
	env->map_size.y = ft_atoi(s + 8);
	while (!ft_isdigit(s[i]))
		i++;
	while (ft_isdigit(s[i]))
		i++;
	env->map_size.x = ft_atoi(s + i);
	ft_strdel(&s);
	return (0);
}

int		ft_init_map(t_env *env)
{
	char	*s;
	int		y;

	y = 0;
	if (!(env->map_list = ft_memalloc(sizeof(t_map))))
		return (2);
	env->map_list->prev = NULL;
	env->map_list->next = NULL;
	if (!(env->map_list->map = ft_memalloc((env->map_size.y + 1) *
		sizeof(char *))))
		return (2);
	ft_print_first_map_line(*env);
	if ((get_next_line(env->fd, &s)) == -1)
		return (3);
	ft_strdel(&s);
	while (y < env->map_size.y)
	{
		if ((get_next_line(env->fd, &s)) == -1)
			return (3);
		env->map_list->map[y] = s;
		y++;
	}
	ft_print_map(env->map_list->map);
	return (0);
}

int		ft_init_all(t_env *env)
{
	int ret;

	if ((ret = ft_get_players(env)))
		return (ret);
	if (ft_get_map_size(env))
		return (3);
	if ((ret = ft_init_map(env)))
		return (ret);
	ft_init_color();
	env->end = 0;
	return (0);
}

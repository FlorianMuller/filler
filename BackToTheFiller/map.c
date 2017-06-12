/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 04:18:18 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/12 16:31:36 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"

void	ft_print_map(char	**map)
{
	int n;

	n = 0;
	move(1, 0);
	while (map[n])
	{
		// ft_printf("%s\n", map[n]);
		printw("%s\n", map[n]);
		n++;
	}
	refresh();
}

int		ft_get_map(t_env *env)
{
	char	*s;
	int		y;

	y = 0;
	env->map_list->next = ft_memalloc(sizeof(t_map));
	env->map_list->next->prev = env->map_list;
	env->map_list->next->next = NULL;
	env->map_list->next->map = ft_memalloc((env->map_size.y + 1) * sizeof(char *));
	get_next_line(FD, &s);
	while (ft_strncmp(s, "    012345", 10) )
	{
		ft_strdel(&s);
		if (get_next_line(FD, &s) == 0)
			return (1);
	}
	ft_strdel(&s);
	while (y < env->map_size.y)
	{
		get_next_line(FD, &s);
		env->map_list->next->map[y] = s;
		y++;
	}
	return (0);
}

int		ft_next_map(t_env *env)
{
	if (env->map_list->next == NULL)
		if (ft_get_map(env))
			return (1);
	env->map_list = env->map_list->next;
	ft_print_map(env->map_list->map);
	return (0);
}

int		ft_prev_map(t_env *env)
{
	if (env->map_list->prev == NULL)
		return (1);
	env->map_list = env->map_list->prev;
	ft_print_map(env->map_list->map);
	return (0);
}

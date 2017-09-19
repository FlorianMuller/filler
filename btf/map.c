/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 04:18:18 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/12 20:50:50 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "back_to_the_filler.h"

int		ft_end(t_env *env, char *str)
{
	int		score_p1;
	int		score_p2;
	char	*s;

	score_p1 = ft_atoi(str + 10);
	if (get_next_line(env->fd, &s) == -1)
		return (3);
	score_p2 = ft_atoi(s + 10);
	ft_strdel(&s);
	if (score_p1 == score_p2)
	{
		init_pair(7, COLOR_YELLOW, COLOR_WHITE);
		init_pair(8, COLOR_CYAN, COLOR_WHITE);
	}
	else if (score_p1 > score_p2)
		init_pair(7, COLOR_YELLOW, COLOR_BLUE);
	else
		init_pair(8, COLOR_CYAN, COLOR_BLUE);
	return (0);
}

int		ft_go_next_map(t_env *env)
{
	char	*s;
	int		ret;

	if ((ret = get_next_line(env->fd, &s)) == 0)
		return (1);
	else if (ret == -1)
		return (3);
	while (ft_strncmp(s, "    012345", 10))
	{
		if (!ft_strncmp(s, "==", 2))
			if (ft_end(env, s))
				return (3);
		ft_strdel(&s);
		if ((ret = get_next_line(env->fd, &s)) == 0)
		{
			ft_strdel(&s);
			return (1);
		}
		else if (ret == -1)
			return (3);
	}
	ft_strdel(&s);
	return (0);
}

int		ft_get_map(t_env *env)
{
	char	*s;
	int		y;
	int		ret;

	if ((ret = ft_go_next_map(env)))
		return (ret);
	y = 0;
	if (!(env->map_list->next = ft_memalloc(sizeof(t_map))))
		return (2);
	env->map_list->next->prev = env->map_list;
	env->map_list->next->next = NULL;
	if (!(env->map_list->next->map = ft_memalloc((env->map_size.y + 1) *
		sizeof(char *))))
		return (2);
	while (y < env->map_size.y)
	{
		if (get_next_line(env->fd, &s) == -1)
			return (3);
		env->map_list->next->map[y] = s;
		y++;
	}
	return (0);
}

int		ft_next_map(t_env *env)
{
	int ret;

	if (env->map_list->next != NULL || !(ret = ft_get_map(env)))
	{
		env->map_list = env->map_list->next;
		ft_print_map(env->map_list->map);
		return (0);
	}
	else
	{
		env->end = 1;
		attron(COLOR_PAIR(6));
		mvprintw(Y_MAP + env->map_size.y + 9, 0, "[Q]       = Quit\n");
		attroff(COLOR_PAIR(6));
	}
	return (ret);
}

void	ft_prev_map(t_env *env)
{
	if (env->map_list->prev != NULL)
	{
		env->map_list = env->map_list->prev;
		ft_print_map(env->map_list->map);
	}
}

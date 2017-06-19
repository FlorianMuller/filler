/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 04:18:18 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/19 17:43:36 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"

void	ft_print_map(char	**map)
{
	t_point	p;
	t_point	max;

	p.x = 0;
	p.y = 0;
	getmaxyx(stdscr, max.y, max.x);
	while (map[p.y])
	{
		move(Y_MAP + p.y, 3);
		while(map[p.y][p.x] && (p.x * 2) + 4 < max.x)
		{
			if (map[p.y][p.x] == 'O')
				attron(COLOR_PAIR(1));
			else if (map[p.y][p.x] == 'X')
				attron(COLOR_PAIR(2));
			else if (map[p.y][p.x] == 'o')
				attron(COLOR_PAIR(3));
			else if (map[p.y][p.x] == 'x')
				attron(COLOR_PAIR(4));
			else if (!ft_isdigit(map[p.y][p.x]))
				attron(COLOR_PAIR(5));
			printw("%c", map[p.y][p.x]);
			if (!(ft_isdigit(map[p.y][p.x]) && map[p.y][p.x + 1] != ' ') && map[p.y][p.x] != ' ')
				printw(" ");
			attrset(A_NORMAL);
			p.x++;
		}
		p.y++;
		p.x = 0;
	}
	printw("\n");
}

void	ft_end(t_env *env, char	*str)
{
	int		score_p1;
	int		score_p2;
	char	*s;

	score_p1 = ft_atoi(str + 10);
	get_next_line(env->fd, &s);
	score_p2 = ft_atoi(s + 10);
	ft_strdel(&s);
	if (score_p1 == score_p2)
	{
		init_pair(7, COLOR_YELLOW, COLOR_WHITE);
		init_pair(8, COLOR_CYAN, COLOR_WHITE);
	}
	else if (score_p1 > score_p2)
		init_pair(7, COLOR_YELLOW, COLOR_BLUE);
		// init_pair(7, COLOR_YELLOW, COLOR_WHITE);
	else
		init_pair(8, COLOR_CYAN, COLOR_BLUE);
		// init_pair(8, COLOR_CYAN, COLOR_WHITE);
}
/*
== O fin: 160
*/
int		ft_go_next_map(t_env *env)
{
	char	*s;

	if (get_next_line(env->fd, &s) == 0)
		return (1);
	while (ft_strncmp(s, "    012345", 10))
	{
		if (!ft_strncmp(s, "==", 2))
			ft_end(env, s);
		ft_strdel(&s);
		if (get_next_line(env->fd, &s) == 0)
		{
			ft_strdel(&s);
			return (1);
		}
	}
	ft_strdel(&s);
	return (0);
}

int		ft_get_map(t_env *env)
{
	char	*s;
	int		y;

	if (ft_go_next_map(env))
		return (1);
	y = 0;
	env->map_list->next = ft_memalloc(sizeof(t_map));
	env->map_list->next->prev = env->map_list;
	env->map_list->next->next = NULL;
	env->map_list->next->map = ft_memalloc((env->map_size.y + 1) * sizeof(char *));
	while (y < env->map_size.y)
	{
		get_next_line(env->fd, &s);
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

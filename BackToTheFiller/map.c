/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 04:18:18 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/15 03:35:37 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"

void	ft_print_map(char	**map)
{
	t_point	p;

	p.x = 0;
	p.y = 0;
	while (map[p.y])
	{
		move(Y_MAP + p.y, 3);
		while(map[p.y][p.x])
		{
			if (map[p.y][p.x] == 'O' || map[p.y][p.x] == 'o')
				attron(COLOR_PAIR(1));
			else if (map[p.y][p.x] == 'X' || map[p.y][p.x] == 'x')
				attron(COLOR_PAIR(2));
			else if (!ft_isdigit(map[p.y][p.x]))
				attron(COLOR_PAIR(4));
			// else if (map[p.y][p.x] == 'o' || map[p.y][p.x] == 'x')
			// 	attron(COLOR_PAIR(3));
			if (map[p.y][p.x] == 'o' || map[p.y][p.x] == 'x')
				attron(A_BOLD);
			printw("%c", map[p.y][p.x]);
			// if (map[p.y][p.x] == 'O' || map[p.y][p.x] == 'o' || map[p.y][p.x] == 'X' || map[p.y][p.x] == 'x' || map[p.y][p.x] == '.')
			if (!(ft_isdigit(map[p.y][p.x]) && map[p.y][p.x + 1] != ' ') && map[p.y][p.x] != ' ')
				printw(" ");
			if (map[p.y][p.x])
			attrset(A_NORMAL);
			p.x++;
		}
		p.y++;
		p.x = 0;
	}
	printw("\n");
	// int n;

	// n = 0;
	// move(1, 0);
	// while (map[n])
	// {
	// 	printw("%s\n", map[n]);
	// 	n++;
	// }
	// refresh();
}

int		ft_get_map(t_env *env)
{
	char	*s;
	int		y;

	if (get_next_line(env->fd, &s) == 0)
		return (1);
	while (ft_strncmp(s, "    012345", 10) )
	{
		ft_strdel(&s);
		if (get_next_line(env->fd, &s) == 0)
		{
			ft_strdel(&s);
			return (1);
		}
	}
	ft_strdel(&s);
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

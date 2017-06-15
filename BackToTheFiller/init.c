/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 03:19:34 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/15 03:31:54 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"

void	ft_get_name(char *s, char **p)
{
	int	i;
	int	len;

	i = ft_strlen(s);
	len = 0;
	while (s[i] != '/')
		i--;
	while (s[i + len] != '.')
		len++;
	*p = ft_strnew(len - 1);
	ft_strncpy(*p, s + i + 1, len - 1);
}

void	ft_get_players(t_env *env)
{
	char	*s;

	env->p1 = NULL;
	env->p2 = NULL;
	while ((!env->p1 || !env->p2) && get_next_line(env->fd, &s) == 1)
	{
		if (!ft_strncmp(s, "$$$", 3))
		{
			if (!ft_strncmp(s + 10, "1", 1))
			{
				ft_get_name(s, &(env->p1));
			}
			else
				ft_get_name(s, &(env->p2));
		}
		ft_strdel(&s);
	}	
}

void	ft_get_map_size(t_env *env)
{
	char	*s;
	int		i;

	i = 0;
	get_next_line(env->fd, &s);
	env->map_size.y = ft_atoi(s + 8);
	while (!ft_isdigit(s[i]))
		i++;
	while (ft_isdigit(s[i]))
		i++;
	env->map_size.x = ft_atoi(s + i);
	ft_strdel(&s);
}

void	ft_print_first_map_line(int fd)
{
	int		i;
	char	*s;

	i = 4;
	get_next_line(fd, &s);
	// attron(COLOR_PAIR(5));
	move(Y_FIRST_MAP_LINE, 7);
	printw(" ");
	while (s[i])
	{
		printw("%c ", s[i]);
		i++;
	}
	// attroff(COLOR_PAIR(5));
	ft_strdel(&s);
}

void	ft_init_map(t_env *env)
{
	char	*s;
	int		y;

	y = 0;
	env->map_list = ft_memalloc(sizeof(t_map));
	env->map_list->prev = NULL;
	env->map_list->next = NULL;
	env->map_list->map = ft_memalloc((env->map_size.y + 1) * sizeof(char *));
	ft_print_first_map_line(env->fd);
	while (y < env->map_size.y)
	{
		get_next_line(env->fd, &s);
		env->map_list->map[y] = s;
		y++;
	}
	ft_print_map(env->map_list->map);
}

void	ft_init_all(t_env *env)
{
	ft_get_players(env);
	ft_get_map_size(env);
	ft_init_map(env);
	ft_init_color();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:19:10 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/09 18:36:50 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "backToTheFiller.h"
#include <ncurses.h>

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
/*
./../fmuller.filler
*/
void	ft_get_players(t_env *env)
{
	char	*s;

	env->p1 = NULL;
	env->p2 = NULL;
	while ((!env->p1 || !env->p2) && get_next_line(0, &s) == 1)
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

	get_next_line(0, &s);
	env->map_size.y = ft_atoi(s + 8);
	while (!ft_isdigit(s[i]))
		i++;
	while (ft_isdigit(s[i]))
		i++;
	env->map_size.x = ft_atoi(s + i);
	ft_strdel(&s);
}

void	ft_get_map(t_env *env)
{
	char	*s;

	while (get_next_line(0, &s) == 1)
	{
		ft_strdel(&s);
	}
	
}

void	ft_get_all(t_env *env)
{
	ft_get_players(env);
	ft_get_map_size(env);
	// ft_get_map(env);
}

int main()
{
	t_env	env;
	char	*s;

	ft_get_all(&env);
	printf("p1: %s\n", env.p1);
	printf("p2: %s\n", env.p2);
	printf("mapsize: %d %d\n", env.map_size.y, env.map_size.x);
	while (get_next_line(0, &s) == 1)
	{
		ft_strdel(&s);
	}
	return 0;
}


/*

Plato yx:
....
....
....
....

Plato yx:
....
....
....
....
*/
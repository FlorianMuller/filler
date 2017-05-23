/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:36:15 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/23 16:24:49 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_passnline(size_t n)
{
	char *s;

	while (n != 0)
	{
		get_next_line(0, &s);
		ft_strdel(&s);
		n--;
	}
}

void	ft_init_map(t_env *env)
{
	int		y;
	char	*s;

	y = 0;
	ft_get_mapsize(env);
	env->map = ft_memalloc((env->mapsize.y + 1) * sizeof(char *));
	ft_passnline(1);
	while (y < env->mapsize.y)
	{
		get_next_line(0, &s);
		env->map[y] = ft_strdup(s + 4);
		ft_strdel(&s);
		y++;
	}

	// int n = 0;
	// ft_printf_fd(fd, "Map:\n");
	// while (env->map[n])
	// {
	// 	ft_printf_fd(fd, "%s\n", env->map[n]);
	// 	n++;
	// }
}

int main()
{
	t_env	env;
	t_point	pos;
	int 	phase;

	phase = 0;
	fd = open("log.txt", O_RDWR);
	ft_get_mytoken(&env);
	ft_init_map(&env);
	while (1)
	{
		ft_get_tokensize(&env);
		ft_get_token(&env);
		ft_resize_token(&env);
		pos = ft_find_pos(env, &phase);
		ft_tabc_del(&(env.token));
		if (pos.y >= env.mapsize.y || pos.y < 0)
			break;
		ft_printf("%d %d\n", pos.y - env.tokendiff.y, pos.x - env.tokendiff.x);
		ft_printf_fd(fd, "====================================\n");
		ft_get_map(&env);
	}
	ft_printf_fd(fd, "\n\n~~~~~END !~~~~~\n");
	ft_tabc_del(&(env.map));
	ft_printf("0 0\n");
	return (0);
}

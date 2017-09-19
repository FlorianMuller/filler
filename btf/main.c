/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:19:10 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/19 17:34:23 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "back_to_the_filler.h"
#include <fcntl.h>

int		ft_error_test(char *s)
{
	if (!ft_strncmp(s, "error", 5) || !ft_strncmp(s, "Usage", 5) ||
		!ft_strncmp(s + 3, "error", 5))
	{
		ft_strdel(&s);
		return (1);
	}
	return (0);
}

void	ft_free_env(t_env *env)
{
	t_map	*p;
	t_map	*p2;

	p = env->map_list;
	ft_strdel(&(env->p1));
	ft_strdel(&(env->p2));
	while (p != NULL)
	{
		ft_tabc_del(&(p->map));
		p2 = p;
		p = p->next;
		ft_memdel((void **)&p);
	}
	env->map_list = NULL;
}

/*
**0: normal end | 1: filler_vm error | 2: malloc error | 3: ge_next_line error
*/

int		ft_end_main(t_env *env, int ret)
{
	char	*s;
	int		ret2;

	ft_end_ncurses();
	if (ret == 0)
		ft_free_env(env);
	if (ret)
		ft_printf("Error:\n");
	if (ret == 1)
	{
		while ((ret2 = get_next_line(env->fd, &s) == 1))
		{
			if (s != NULL)
				ft_printf("%s\n", s);
			ft_strdel(&s);
		}
		if (ret2 == -1)
			ret = 3;
	}
	if (ret == 2)
		ft_printf("Malloc failed\n");
	else if (ret == 3)
		ft_printf("get_next_line failed\n");
	close(env->fd);
	return (ret);
}

int		main(void)
{
	int		ret;
	t_env	env;

	mknod("btf/coolpipe", S_IFIFO | 0666, 0);
	env.fd = open("btf/coolpipe", O_RDONLY);
	if (ft_init_ncurses())
		return (1);
	if ((ret = ft_init_all(&env)))
		return (ft_end_main(&env, ret));
	ft_first_print(&env);
	if ((ret = ft_while(&env)))
		return (ft_end_main(&env, ret));
	return (ft_end_main(&env, 0));
}

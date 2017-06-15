/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:19:10 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/14 16:48:16 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"
#include <fcntl.h>

// void	ft_passnline(size_t n)
// {
// 	char *s;

// 	while (n != 0)
// 	{
// 		get_next_line(env->fd, &s);
// 		ft_strdel(&s);
// 		n--;
// 	}
// }

int main()
{
	t_env	env;
	// char	*s;
	// int		fd;

	mknod("coolpipe", S_IFIFO | 0666, 0);
	env.fd = open("coolpipe", O_RDONLY);

	if (ft_init_ncurses())
		return (1);
	ft_init_all(&env);
	ft_first_print(&env);
	
	ft_while(&env);
	
	// while (get_next_line(env.fd, &s) == 1)
	// {
	// 	ft_strdel(&s);
	// }
	ft_end_ncurses(env.fd);
	return (0);
}

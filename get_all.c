/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:07:47 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/10 00:45:06 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_mytoken(t_env *env)
{
	char	*s;

	get_next_line(0, &s);
	if (!ft_strncmp(s + 10, "1", 1))
		env->mytoken = 'O';
	else
		env->mytoken = 'X';
	ft_strdel(&s);
	
	// ft_printf_fd(fd, "mytoken: %c\n", env->mytoken);
}

void	ft_get_mapsize(t_env *env)
{
	char	*s;
	int		i;

	i = 0;
	get_next_line(0, &s);
	env->mapsize.y = ft_atoi(s + 8);
	while (!ft_isdigit(s[i]))
		i++;
	while (ft_isdigit(s[i]))
		i++;
	env->mapsize.x = ft_atoi(s + i);
	ft_strdel(&s);

	// ft_printf_fd(fd, "mapsize.y: %d\n", env->mapsize.y);
	// ft_printf_fd(fd, "mapsize.x: %d\n", env->mapsize.x);
	
	// char	*s;

	// get_next_line(0, &s);
	// env->mapsize.y = ft_atoi(s + 8);
	// env->mapsize.x = ft_atoi(s + 11);
	// ft_strdel(&s);
}



void	ft_get_map(t_env *env)
{
	char	*s;
	int		y;

	y = 0;
	ft_passnline(2);
	while (y < env->mapsize.y)
	{
		get_next_line(0, &s);
		 ft_strcpy(env->map[y], s + 4);
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

void	ft_get_tokensize(t_env *env)
{
	char	*s;

	get_next_line(0, &s);
	env->tokensize.y = ft_atoi(s + 6);
	env->tokensize.x = ft_atoi(s + 8);
	ft_strdel(&s);
	
	// ft_printf_fd(fd, "tokensize.y: %d\n", env->tokensize.y);
	// ft_printf_fd(fd, "tokensize.x: %d\n", env->tokensize.x);
}

void	ft_get_token(t_env *env)
{
	char	*s;
	int		y;

	y = 0;
	env->token = ft_memalloc((env->tokensize.y + 1) * sizeof(char *));
	while (y < env->tokensize.y)
	{
		get_next_line(0, &s);
		env->token[y] = ft_strdup(s);
		ft_strdel(&s);
		y++;
	}

	// int n = 0;
	// ft_printf_fd(fd, "Token:\n");
	// while (env->token[n])
	// {
	// 	ft_printf_fd(fd, "%s\n", env->token[n]);
	// 	n++;
	// }
}

// $$$ exec p1 : [./fmuller.filler
//           10

// Plateau 15 17:
        // 8  11

// 000 .................
    // 4


// Piece 2 3:
//       6 8

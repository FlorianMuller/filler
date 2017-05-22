/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:33:15 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/22 20:43:18 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_token_diff(t_env *env)
{
	t_point	p;

	ft_set_point(&p, 0, 0);
	ft_set_point(&(env->tokendiff), -1, -1);
	while (env->token[p.y])
	{
		if (env->token[p.y][p.x] == '*' && env->tokendiff.y == -1)
			ft_set_point(&(env->tokendiff), p.x, p.y);
		if (env->token[p.y][p.x] == '*' && p.x < env->tokendiff.x)
			env->tokendiff.x = p.x;
		ft_point_plus(&p, env->tokensize.x - 1);
	}

	// ft_printf_fd(fd, "DIFF: x: %3d | y: %3d\n", env->tokendiff.x, env->tokendiff.y);
}

void	ft_get_new_tokensize(t_env *env, t_point *size)
{
	t_point	p;

	ft_set_point(&p, 0, 0);
	ft_set_point(size, 0, 0);
	while (env->token[p.y])
	{
		if (env->token[p.y][p.x] == '*' && p.x > size->x)
			size->x = p.x;
		if (env->token[p.y][p.x] == '*' && p.y > size->y)
			size->y = p.y;
		ft_point_plus(&p, env->tokensize.x - 1);
	}
	size->x = size->x - env->tokendiff.x + 1;
	size->y = size->y - env->tokendiff.y + 1;

	// ft_printf_fd(fd, "SIZE: x: %3d | y: %3d\n", size->x, size->y);
}

void	ft_get_new_token(t_env *env, char ***new_tok, t_point new_toksize)
{
	int	y;

	y = 0;
	*new_tok = ft_memalloc((new_toksize.y + 1) * sizeof(char *));
	while (y < new_toksize.y)
	{
		(*new_tok)[y] = ft_strnew(new_toksize.x);
		ft_strncpy((*new_tok)[y], (env->token[y + env->tokendiff.y]) + env->tokendiff.x, new_toksize.x);
		y++;
	}
}

void	ft_resize_token(t_env *env)
{
	char	**new_tok;
	t_point	new_toksize;

	ft_get_token_diff(env);
	ft_get_new_tokensize(env, &new_toksize);
	ft_get_new_token(env, &new_tok, new_toksize);
	ft_tabc_del(&(env->token));
	env->token = new_tok;
	env->tokensize = new_toksize;

	int n = 0;
	ft_printf_fd(fd, "New Token:\n");
	while (env->token[n])
	{
		ft_printf_fd(fd, "%s\n", env->token[n]);
		n++;
	}
}
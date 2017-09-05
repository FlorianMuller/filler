/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:49:08 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/05 17:51:12 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_is_adv(char c, char mytoken)
{
	if (mytoken == 'O')
		return (c == 'x' || c == 'X');
	else
		return (c == 'o' || c == 'O');
}

int		ft_check_pos(t_env env, t_point pos)
{
	t_point p;
	int		cross;

	cross = 0;
	ft_set_point(&p, 0, 0);
	while (env.token[p.y])
	{
		if (pos.y + p.y >= env.mapsize.y)
			return (0);
		while (env.token[p.y][p.x])
		{
			if (pos.x + p.x >= env.mapsize.x
				|| (ft_is_adv(env.map[pos.y + p.y][pos.x + p.x], env.mytoken)
					&& env.token[p.y][p.x] == '*'))
				return (0);
			if (env.token[p.y][p.x] == '*'
				&& env.map[pos.y + p.y][pos.x + p.x] == env.mytoken)
				cross++;
			p.x++;
		}
		ft_set_point(&p, 0, p.y + 1);
	}
	return ((cross == 1) ? 1 : 0);
}

void	ft_point_plus(t_point *pos, int x_max)
{
	if (pos->x == x_max)
	{
		pos->x = 0;
		pos->y++;
	}
	else
		pos->x++;
}

void	ft_point_minus(t_point *pos, int x_max)
{
	if (pos->x == 0)
	{
		pos->x = x_max;
		pos->y--;
	}
	else
		pos->x--;
}

t_point	ft_find_pos(t_env env, int *phase)
{
	t_point	pos;

	if (*phase == 0 && ft_is_in_contact(env))
		*phase = 1;
	if (*phase > 0 && *phase < 10)
	{
		pos = ft_surround(env);
		if (pos.x == -1 && pos.y == -1)
		{
			(*phase)++;
			pos = ft_get_closer(env);
		}
		else
			*phase = 1;
	}
	if (*phase == 0)
		pos = ft_get_closer(env);
	if (*phase == 10)
		pos = ft_complete(env);
	return (pos);
}

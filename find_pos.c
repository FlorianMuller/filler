/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:49:08 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/22 20:07:33 by fmuller          ###   ########.fr       */
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

void	ft_set_point(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
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
		 		cross ++;
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


t_point	ft_find_pos(t_env env)
{
	t_point	pos;
	// t_point	valid_pos;

	// ft_set_point(&pos, 0, 0);
	// while (pos.y != env.mapsize.y)
	// {
	// 	if (ft_check_pos(env, pos))
	// 	{
	// 		valid_pos = pos;
	// 		ft_printf_fd(fd, "|Pos:\n%d %d\n", pos.y, pos.x);
	// 		ft_printf_fd(fd, "|dist: %d\n", ft_dist_to_adv(env, pos));
	// 	}
	// 	ft_point_plus(&pos, env.mapsize.x - 1);
	// }

	pos = ft_get_closer(env);
	ft_printf_fd(fd, "POSITION:\n%d %d\n", pos.y, pos.x);
	return (pos);
}
	// if (env.mytoken == 'O')
	// 	ft_set_point(&pos, env.mapsize.x - 1, env.mapsize.y - 1);
	// else
	// 	ft_set_point(&pos, 0, 0);
	// while (pos.y != env.mapsize.y && pos.y >= 0 && !ft_check_pos(env, pos))
	// {
	// 	// ft_printf_fd(fd, "pos.x: %d | pos.y: %d\n", pos.x, pos.y);
	// 	if (env.mytoken == 'O')
	// 		ft_point_minus(&pos, env.mapsize.x - 1);
	// 	else
	// 		ft_point_plus(&pos, env.mapsize.x - 1);
	// }

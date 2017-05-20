/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:49:08 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/20 03:37:36 by fmuller          ###   ########.fr       */
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
		if (pos.y + p.y >= env.mapsize.y && ft_strchr(env.token[p.y], '*'))
			return (0);
		while (env.token[p.y][p.x++])
		{
			if (env.token[p.y][p.x - 1] != '*')
				continue;
			if (pos.x + p.x - 1 >= env.mapsize.x
				|| (ft_is_adv(env.map[pos.y + p.y][pos.x + p.x - 1], env.mytoken)
					&& env.token[p.y][p.x - 1] == '*'))
				return (0);
		 	cross += (env.map[pos.y + p.y][pos.x + p.x - 1] == env.mytoken) ? 1: 0;
		}
		ft_set_point(&p, 0, p.y + 1);
	}
	return ((cross == 1) ? 1 : 0);
}

// if (pos.y + p.y >= env.mapsize.y && ft_strchr(env.token[p.y], '*'))
// 	return (0);
// else if (ft_strchr(env.token[p.y], '*'))
// 	while (env.token[p.y][p.x])
// 	{
// 		if ((pos.x + p.x >= env.mapsize.x && env.token[p.y][p.x] == env.mytoken)
// 			|| (ft_is_adv(env.map[pos.y + p.y][pos.x + p.x], env.mytoken)
// 				&& env.token[p.y][p.x] == '*'))
// 			return (0);
// 		else if (env.token[p.y][p.x] == env.mytoken)
// 			if (env.map[pos.y + p.y][pos.x + p.x] == env.mytoken && env.token[p.y][p.x] == '*')
// 		 		cross++;
// 		p.x++;
// 	}
// p.x = 0;
// p.y++;

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

	if (env.mytoken == 'O')
		ft_set_point(&pos, env.mapsize.x - 1, env.mapsize.y - 1);
	else
		ft_set_point(&pos, 0, 0);
	while (!ft_check_pos(env, pos) && pos.y != env.mapsize.y && pos.y != env.mapsize.y && pos.y >= 0)
	{
		ft_printf_fd(fd, "pos.x: %d | pos.y: %d\n", pos.x, pos.y);
		if (env.mytoken == 'O')
			ft_point_minus(&pos, env.mapsize.x - 1);
		else
			ft_point_plus(&pos, env.mapsize.x - 1);
	}
	ft_printf_fd(fd, "Pos:\n%d %d\n", pos.y, pos.x);
	return (pos);
}

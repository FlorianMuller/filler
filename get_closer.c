/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:14:40 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/05 17:23:22 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_dist(t_point a, t_point b)
{
	return (ft_power(ft_abs_val(b.x - a.x), 2) +
		ft_power(ft_abs_val(b.y - a.y), 2));
}

int		ft_dist_to_adv(t_env env, t_point pos)
{
	t_point	advpos;
	t_point	mypos;
	t_point	p;
	int		dist;
	int		best_dist;

	ft_set_point(&advpos, 0, 0);
	while (advpos.y != env.mapsize.y)
	{
		if (ft_is_adv(env.map[advpos.y][advpos.x], env.mytoken))
		{
			ft_set_point(&p, 0, 0);
			while (env.token[p.y])
			{
				ft_set_point(&mypos, pos.x + p.x, pos.y + p.y);
				dist = ft_dist(mypos, advpos);
				if (best_dist == -1 || dist < best_dist)
					best_dist = dist;
				ft_point_plus(&p, env.tokensize.x - 1);
			}
		}
		ft_point_plus(&advpos, env.mapsize.x - 1);
	}
	return (best_dist);
}

t_point	ft_get_closer(t_env env)
{
	t_point	pos;
	t_point	best_pos;
	int		dist;
	int		best_dist;

	ft_set_point(&pos, 0, 0);
	best_dist = -1;
	while (pos.y != env.mapsize.y)
	{
		if (ft_check_pos(env, pos))
		{
			dist = ft_dist_to_adv(env, pos);
			if (best_dist == -1 || dist < best_dist)
			{
				best_dist = dist;
				best_pos = pos;
			}
		}
		ft_point_plus(&pos, env.mapsize.x - 1);
	}
	return (best_pos);
}

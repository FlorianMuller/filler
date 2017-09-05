/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surround.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:12:34 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/05 17:46:29 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_is_in_contact(t_env env)
{
	t_point	pos;
	int		contact;

	contact = 0;
	ft_set_point(&pos, 0, 0);
	while (pos.y != env.mapsize.y)
	{
		if (env.map[pos.y][pos.x] == env.mytoken)
		{
			if (pos.x + 1 < env.mapsize.x &&
				ft_is_adv(env.map[pos.y][pos.x + 1], env.mytoken))
				contact = 1;
			if (pos.x - 1 > 0 && ft_is_adv(env.map[pos.y][pos.x - 1],
				env.mytoken))
				contact = 1;
			if (pos.y + 1 < env.mapsize.y &&
				ft_is_adv(env.map[pos.y + 1][pos.x], env.mytoken))
				contact = 1;
			if (pos.y - 1 > 0 && ft_is_adv(env.map[pos.y - 1][pos.x],
				env.mytoken))
				contact = 1;
		}
		ft_point_plus(&pos, env.mapsize.x - 1);
	}
	return (contact);
}

void	ft_add_contact(t_env env, t_point pos, t_point p, int *contact)
{
	if (pos.x + p.x + 1 < env.mapsize.x &&
		ft_is_adv(env.map[pos.y + p.y][pos.x + p.x + 1], env.mytoken))
		(*contact)++;
	if (pos.x + p.x - 1 > 0 &&
		ft_is_adv(env.map[pos.y + p.y][pos.x + p.x - 1], env.mytoken))
		(*contact)++;
	if (pos.y + p.y + 1 < env.mapsize.y &&
		ft_is_adv(env.map[pos.y + p.y + 1][pos.x + p.x], env.mytoken))
		(*contact)++;
	if (pos.y + p.y - 1 > 0 &&
		ft_is_adv(env.map[pos.y + p.y - 1][pos.x + p.x], env.mytoken))
		(*contact)++;
	if ((pos.y + p.y + 1 < env.mapsize.y) && (pos.x + p.x - 1 > 0) &&
	ft_is_adv(env.map[pos.y + p.y + 1][pos.x + p.x - 1], env.mytoken))
		(*contact)++;
	if ((pos.y + p.y + 1 < env.mapsize.y) && (pos.x + p.x + 1 <
		env.mapsize.x) &&
	ft_is_adv(env.map[pos.y + p.y + 1][pos.x + p.x + 1], env.mytoken))
		(*contact)++;
	if ((pos.y + p.y - 1 > 0) && (pos.x + p.x - 1 > 0) &&
	ft_is_adv(env.map[pos.y + p.y - 1][pos.x + p.x - 1], env.mytoken))
		(*contact)++;
	if ((pos.y + p.y - 1 > 0) && (pos.x + p.x + 1 < env.mapsize.x) &&
	ft_is_adv(env.map[pos.y + p.y - 1][pos.x + p.x + 1], env.mytoken))
		(*contact)++;
}

int		ft_contact(t_env env, t_point pos)
{
	t_point	p;
	int		contact;

	contact = 0;
	ft_set_point(&p, 0, 0);
	while (env.token[p.y])
	{
		if (env.token[p.y][p.x] == '*')
			ft_add_contact(env, pos, p, &contact);
		ft_point_plus(&p, env.tokensize.x - 1);
	}
	return (contact);
}

t_point	ft_surround(t_env env)
{
	t_point	pos;
	t_point	best_pos;
	int		contact;
	int		best_contact;

	ft_set_point(&pos, 0, 0);
	best_contact = -1;
	while (pos.y != env.mapsize.y)
	{
		if (ft_check_pos(env, pos))
		{
			contact = ft_contact(env, pos);
			if (best_contact == -1 || contact > best_contact)
			{
				best_contact = contact;
				best_pos = pos;
			}
		}
		ft_point_plus(&pos, env.mapsize.x - 1);
	}
	if (best_contact == 0)
		ft_set_point(&best_pos, -1, -1);
	return (best_pos);
}

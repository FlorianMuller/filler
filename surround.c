/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surround.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:12:34 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/23 19:28:59 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_is_in_contact(t_env env)
{
		// ft_printf_fd(fd, "	A\n");
	t_point	pos;
	int		contact;

	contact = 0;
	ft_set_point(&pos, 0, 0);
	while (pos.y != env.mapsize.y)
	{
		if (env.map[pos.y][pos.x] == env.mytoken)
		{
			if (pos.x + 1 < env.mapsize.x && ft_is_adv(env.map[pos.y][pos.x + 1], env.mytoken))
				contact = 1;
			if (pos.x - 1 > 0 && ft_is_adv(env.map[pos.y][pos.x - 1], env.mytoken))
				contact = 1;
			if (pos.y + 1 < env.mapsize.y && ft_is_adv(env.map[pos.y + 1][pos.x], env.mytoken))
				contact = 1;
			if (pos.y - 1 > 0 && ft_is_adv(env.map[pos.y - 1][pos.x], env.mytoken))
				contact = 1;
			// if (ft_is_adv(env.map[pos.y + p.y + 1][pos.x + p.x - 1], env.mytoken))
			// 	contact = 1;
			// if (ft_is_adv(env.map[pos.y + p.y + 1][pos.x + p.x + 1], env.mytoken))
			// 	contact = 1;
			// if (ft_is_adv(env.map[pos.y + p.y - 1][pos.x + p.x - 1], env.mytoken))
			// 	contact = 1;
			// if (ft_is_adv(env.map[pos.y + p.y - 1][pos.x + p.x + 1], env.mytoken))
			// 	contact = 1;
		}
		ft_point_plus(&pos, env.mapsize.x - 1);
	}
	return (contact);
}

int		ft_contact(t_env env, t_point pos)
{
	t_point	p;
	int		contact;

	contact = 0;
	ft_set_point(&p, 0, 0);
	
	// ft_printf_fd(fd, "tokensize.y: %d\n", env.tokensize.y);
	// ft_printf_fd(fd, "tokensize.x: %d\n", env.tokensize.x);
	// int n = 0;
	// ft_printf_fd(fd, "Token:\n");
	// while (env.token[n])
	// {
	// 	ft_printf_fd(fd, "%s\n", env.token[n]);
	// 	n++;
	// }

	while (env.token[p.y])
	{
		// ft_printf_fd(fd, "	===|x: %2d | y: %2d|c: %c|===\n", p.x, p.y, env.token[p.y][p.x]);
		if (env.token[p.y][p.x] == '*')
		{
			// ft_printf_fd(fd, "	%c\n", env.map[pos.y + p.y][pos.x + p.x + 1]);
			if (pos.x + p.x + 1 < env.mapsize.x && ft_is_adv(env.map[pos.y + p.y][pos.x + p.x + 1], env.mytoken))
			{
				contact++;
				// ft_printf_fd(fd, "[X]\n");
			}
			// else
				// ft_printf_fd(fd, "...\n");

			// ft_printf_fd(fd, "	%c\n", env.map[pos.y + p.y][pos.x + p.x - 1]);
			if (pos.x + p.x - 1 > 0 && ft_is_adv(env.map[pos.y + p.y][pos.x + p.x - 1], env.mytoken))
			{
				contact++;
				// ft_printf_fd(fd, "[X]\n");
			}
			// else
				// ft_printf_fd(fd, "...\n");
			
			// ft_printf_fd(fd, "	%c\n", env.map[pos.y + p.y + 1][pos.x + p.x]);
			if (pos.y + p.y + 1 < env.mapsize.y && ft_is_adv(env.map[pos.y + p.y + 1][pos.x + p.x], env.mytoken))
			{
				contact++;
				// ft_printf_fd(fd, "[X]\n");
			}
			// else
				// ft_printf_fd(fd, "...\n");	
			
			// ft_printf_fd(fd, "	%c\n", env.map[pos.y + p.y - 1][pos.x + p.x]);
			if (pos.y + p.y - 1 > 0 && ft_is_adv(env.map[pos.y + p.y - 1][pos.x + p.x], env.mytoken))
			{
				contact++;
				// ft_printf_fd(fd, "[X]\n");
			}
			// else
				// ft_printf_fd(fd, "...\n");	
			
			
			// ft_printf_fd(fd, "	%c\n", env.map[pos.y + p.y + 1][pos.x + p.x - 1]);
			if ((pos.y + p.y + 1 < env.mapsize.y) && (pos.x + p.x - 1 > 0) && ft_is_adv(env.map[pos.y + p.y + 1][pos.x + p.x - 1], env.mytoken))
			{
				contact++;
				// ft_printf_fd(fd, "[X]\n");
			}
			// else
				// ft_printf_fd(fd, "...\n");	
			
			// ft_printf_fd(fd, "	%c\n", env.map[pos.y + p.y + 1][pos.x + p.x + 1]);
			if ((pos.y + p.y + 1 < env.mapsize.y) && (pos.x + p.x + 1 < env.mapsize.x) && ft_is_adv(env.map[pos.y + p.y + 1][pos.x + p.x + 1], env.mytoken))
			{
				contact++;
				// ft_printf_fd(fd, "[X]\n");
			}
			// else
				// ft_printf_fd(fd, "...\n");	
			
			// ft_printf_fd(fd, "	%c\n", env.map[pos.y + p.y - 1][pos.x + p.x - 1]);
			if ((pos.y + p.y - 1 > 0) && (pos.x + p.x - 1 > 0) && ft_is_adv(env.map[pos.y + p.y - 1][pos.x + p.x - 1], env.mytoken))
			{
				contact++;
				// ft_printf_fd(fd, "[X]\n");
			}
			// else
				// ft_printf_fd(fd, "...\n");	
			
			// ft_printf_fd(fd, "	%c\n", env.map[pos.y + p.y - 1][pos.x + p.x + 1]);
			if ((pos.y + p.y - 1 > 0) && (pos.x + p.x + 1 < env.mapsize.x) && ft_is_adv(env.map[pos.y + p.y - 1][pos.x + p.x + 1], env.mytoken))
			{
				contact++;
				// ft_printf_fd(fd, "[X]\n");
			}
			// else
				// ft_printf_fd(fd, "...\n");	
		}
		// ft_printf_fd(fd, "fin\n");
		ft_point_plus(&p, env.tokensize.x - 1);
		// ft_printf_fd(fd, "fin!\n");
	}

	return (contact);
}

t_point	ft_surround(t_env env)
{
	t_point	pos;
	t_point	best_pos;
	int	contact;
	int	best_contact;

	ft_set_point(&pos, 0, 0);
	best_contact = -1;
	while (pos.y != env.mapsize.y)
	{
		if (ft_check_pos(env, pos))
		{
			// ft_printf_fd(fd, "==POS==\n");
			// ft_printf_fd(fd, "X: %3d | Y: %3d\n", pos.x, pos.y);
			contact = ft_contact(env, pos);
			// ft_printf_fd(fd, "CONTACT: %d\n", contact);
			if (best_contact == -1 || contact > best_contact)
			{
				// ft_printf_fd(fd, "BEST CONTACT !\n");
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

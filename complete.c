/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:35:03 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/05 17:50:18 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	ft_complete(t_env env)
{
	t_point	pos;

	ft_set_point(&pos, 0, 0);
	while (pos.y != env.mapsize.y && !ft_check_pos(env, pos))
		ft_point_plus(&pos, env.mapsize.x - 1);
	return (pos);
}

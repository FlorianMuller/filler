/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:36:44 by fmuller           #+#    #+#             */
/*   Updated: 2017/05/23 19:35:48 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
#	include <stdio.h>
#	include <fcntl.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_env
{
	char	mytoken;
	char	**map;
	t_point	mapsize;
	char	**token;
	t_point	tokensize;
	t_point	tokendiff;
}				t_env;

// int fd;

void			ft_passnline(size_t n);
void			ft_set_point(t_point *p, int x, int y);
void			ft_point_plus(t_point *pos, int x_max);
void			ft_point_minus(t_point *pos, int x_max);
int				ft_is_adv(char c, char mytoken);


void			ft_get_mytoken(t_env *env);
void			ft_get_mapsize(t_env *env);
void			ft_get_map(t_env *env);
void			ft_get_tokensize(t_env *env);
void			ft_get_token(t_env *env);
void			ft_resize_token(t_env *env);

t_point			ft_find_pos(t_env env, int *phase);
int				ft_check_pos(t_env env, t_point pos);

t_point			ft_get_closer(t_env env);
int				ft_dist_to_adv(t_env env, t_point mypos);
int				ft_dist(t_point a, t_point b);

t_point			ft_surround(t_env env);
int				ft_is_in_contact(t_env env);

t_point			ft_complete(t_env env);

#endif

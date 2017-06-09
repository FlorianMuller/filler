/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backToTheFiller.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:30:00 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/09 18:35:39 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTOTHEFILLER
# define BACKTOTHEFILLER

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_env
{
	char		*p1;
	char		*p2;
	char		***map;
	t_point		map_size;
}				t_env;

#endif

/*
Idée bous
Stat.txt
->ecris des stats de victoire/defaite

$fmuller
$carly
	#map00
		-p1: fmuller: 90(90%)
		-p2: carly: 10 (10%)

		-p1: carly: 10 (10%)
		-p2: fmuller: 90(90%)


$fmuller
$cpoulet
	#map03
		-p1: fmuller: 6 (60%)
		-p2: carly:  4 (10%)

		-p1: carly: 10 (10%)
		-p2: fmuller: 90(90%)
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backToTheFiller.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:30:00 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/05 17:10:28 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTOTHEFILLER
# define BACKTOTHEFILLER

# include "../libft/libft.h"
# include <ncurses.h>

# define Y_TITLE 0
# define Y_NAME 4 
# define Y_FIRST_MAP_LINE 8
# define Y_MAP 9


typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_map
{
	char			**map;
	struct s_map	*next;
	struct s_map	*prev;
}				t_map;

typedef struct	s_env
{
	char		*p1;
	char		*p2;
	t_map		*map_list;
	t_point		map_size;
	int			fd;
}				t_env;


void			ft_init_all(t_env *env);

int				ft_init_ncurses();
void			ft_init_color();
void			ft_end_ncurses();

void			ft_first_print(t_env *env);
void			ft_print_title();
void			ft_print_name(t_env *env);
void			ft_print_first_map_line(t_env env);
void			ft_print_button(t_env env, int forward, int pause);
void			ft_print_speed(t_env env, int input);

void			ft_while(t_env *env);

int				ft_next_map(t_env *env);
int				ft_prev_map(t_env *env);
void			ft_print_map(char	**map);

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
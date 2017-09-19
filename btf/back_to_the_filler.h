/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_the_filler.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:30:00 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/12 16:55:23 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACK_TO_THE_FILLER_H
# define BACK_TO_THE_FILLER_H

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
	int			end;
}				t_env;

int				ft_init_all(t_env *env);
int				ft_init_ncurses();
void			ft_init_color();
void			ft_end_ncurses();
void			ft_first_print(t_env *env);
void			ft_print_title();
void			ft_print_name(t_env *env);
void			ft_print_first_map_line(t_env env);
void			ft_print_button(t_env env, int forward, int pause);
void			ft_print_speed(t_env env, int input);
int				ft_while(t_env *env);
int				ft_next_map(t_env *env);
void			ft_prev_map(t_env *env);
void			ft_print_map(char	**map);
void			ft_resize(t_env *env);
int				ft_error_test(char *s);

#endif

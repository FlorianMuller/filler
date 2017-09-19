/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 22:03:37 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/11 20:07:28 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "back_to_the_filler.h"

int		ft_input(int *forward, int *speed, int *pause)
{
	int	input;

	input = getch();
	if (input == '1')
		*speed = 800;
	else if (input == '2')
		*speed = 400;
	else if (input == '3')
		*speed = 200;
	else if (input == '4')
		*speed = 50;
	else if (input == '5')
		*speed = 15;
	else if (input == '6')
		*speed = 5;
	else if (input == '0')
		*speed = 0;
	else if (input == ' ')
		*pause = (*pause == 1) ? 0 : 1;
	else if (input == KEY_RIGHT)
		*forward = 1;
	else if (input == KEY_LEFT)
		*forward = 0;
	timeout(((*pause == 1) ? -1 : *speed));
	return (input);
}

void	ft_print_speed(t_env env, int input)
{
	int		n;
	t_point	p;

	n = 0;
	p.y = Y_MAP + env.map_size.y + 6;
	p.x = ((((env.map_size.x * 2 + 1) - 41) / 2) + 7);
	while (n < 7)
	{
		if (input - '0' == n + 1 || (input - '0' == 0 && n == 6))
			attron(COLOR_PAIR(9));
		mvprintw(p.y, p.x, "+---+");
		mvprintw(p.y + 1, p.x, "| %d |", ((n != 6) ? n + 1 : 0));
		mvprintw(p.y + 2, p.x, "+---+");
		attrset(A_NORMAL);
		mvprintw(p.y, p.x + 5, " ");
		mvprintw(p.y + 1, p.x + 5, " ");
		mvprintw(p.y + 2, p.x + 5, " ");
		p.x += 6;
		n++;
	}
}

void	ft_modify_ui(t_env *env, int input, int pause, int forward)
{
	if (input == KEY_RESIZE)
	{
		ft_resize(env);
		ft_print_button(*env, forward, pause);
		ft_print_speed(*env, input);
		refresh();
	}
	else if (input != ERR)
	{
		if (input >= '0' && input <= '6')
			ft_print_speed(*env, input);
		else
			ft_print_button(*env, forward, pause);
		refresh();
	}
}

int		ft_change_map(t_env *env, int inp, int pause, int forward)
{
	int		ret;

	if ((!pause && inp == ERR) || (inp == KEY_RIGHT || inp == KEY_LEFT))
	{
		if (forward)
		{
			if ((ret = ft_next_map(env) > 1))
				return (ret);
		}
		else
			ft_prev_map(env);
		refresh();
	}
	return (0);
}

/*
** while ((inp = ft_input(&forward, &speed, &pause)) != 'q' && inp != 'Q')
*/

int		ft_while(t_env *env)
{
	int	forward;
	int	speed;
	int	pause;
	int inp;
	int	ret;

	forward = 1;
	speed = 200;
	pause = 0;
	while (((inp = ft_input(&forward, &speed, &pause)) != 'q' && inp != 'Q')
		|| !(env->end))
	{
		ft_modify_ui(env, inp, pause, forward);
		if ((ret = ft_change_map(env, inp, pause, forward)))
			return (ret);
	}
	return (0);
}

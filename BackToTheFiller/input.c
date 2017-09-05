/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 22:03:37 by fmuller           #+#    #+#             */
/*   Updated: 2017/08/31 18:01:52 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"

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
		*pause = (*pause == 1) ? 0 : 1 ;
	else if (input == KEY_RIGHT)
		*forward = 1;
	else if (input == KEY_LEFT)
		*forward = 0;
	timeout(((*pause == 1) ? -1 : *speed));
	return (input);
}

#define SPACE_NUM 10

void	ft_print_button(t_env env, int forward, int pause)
{
	attrset(A_NORMAL);
	t_point	p;

	p.y = Y_MAP + env.map_size.y + 1;
	p.x = ((((env.map_size.x * 2 + 1) - 28) / 2) + 7);
	mvprintw(p.y, 0, "                                                                        ");
	if (!forward)
		attron(COLOR_PAIR(9));
	mvprintw(p.y, p.x, " // ");
	mvprintw(p.y + 1, p.x, " \\\\ ");
	attrset(A_NORMAL);
	p.x += 4;
	mvprintw(p.y, p.x, "         %s         ", ((pause == 0) ? "||" : "|\\"));
	mvprintw(p.y + 1, p.x, "         %s         ", ((pause == 0) ? "||" : "|/"));
	p.x += 20;
	if (forward)
		attron(COLOR_PAIR(9));
	mvprintw(p.y, p.x, " \\\\ ");
	mvprintw(p.y + 1, p.x, " // ");
	attrset(A_NORMAL);
	mvprintw(p.y + 3, ((((env.map_size.x * 2 + 1) - 43) / 2) + 7),"[LeftArrow]      [Space]       [RightArrow]");
}

void	ft_print_speed(t_env env, int input)
{
	int	n;
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

void	ft_resize(t_env *env)
{
	clear();
	ft_print_title();
	ft_print_name(env);
	ft_print_first_map_line(*env);
	ft_print_map(env->map_list->map);
	mvprintw(Y_MAP + env->map_size.y + 9, 0, "[Q]       = Quit\n[cmd +/-] = Zoom");
}

void	ft_while(t_env *env)
{
	int	forward;
	int	speed;
	int	pause;
	int input;

	forward = 1;
	speed = 200;
	pause = 0;

	while ((input = ft_input(&forward, &speed, &pause)) != 'q' && input != 'Q')
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
		if ((!pause && input == ERR) || (input == KEY_RIGHT  || input == KEY_LEFT))
		{
			if (forward)
				ft_next_map(env);				
			else
				ft_prev_map(env);
			refresh();
		}
	}
}

/*
         //          |\          \\
         \\          |/          //
                                   
 [LeftArrow]      [Space]       [RightArrow]

         //          ||          \\
         \\          ||          //
                         
[LeftArrow]  [Space]   [RightArrow]


         1   2   3   4   5   6   0
 
 ___  .___. +---+  ---   ___   ___   ___  
| 1 | | 2 | | 3 | | 4 | | 5 | | 6 | | 0 | 
 ---  .---. +---+  ---   ---   ---   ---  
*/

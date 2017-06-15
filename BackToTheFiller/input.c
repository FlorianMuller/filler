/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 22:03:37 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/15 19:15:25 by fmuller          ###   ########.fr       */
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
   // 023 
 // . . . . . . . . . . . . . . . . . . . . . . . O O O O O O . . . . . . . . . . . 
/*
           //          |\          \\
           \\          |/          //

         //          |\          \\
         \\          |/          //
                                   
 [LeftArrow]      [Space]       [RightArrow]

         //     ||     \\
         \\     ||     //
                         
[LeftArrow]  [Space]   [RightArrow]

*/

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
		if (input != ERR)
		{
			ft_print_button(*env, forward, pause);
			refresh();
		}
		if (input == ERR || (/*pause == 1 &&*/ (input == KEY_RIGHT  || input == KEY_LEFT)))
		{
			if (forward)
			{
				if (ft_next_map(env))
				{
					attron(COLOR_PAIR(10));
					mvprintw(Y_MAP + env->map_size.y, 0, "================================================================================================");
					//                                   "[1]  + 16275 exit 2     ./../filler_vm -f ../maps/map00 -p2 ./../fmuller.filler -p1  >&coolpipe"
					attrset(A_NORMAL);
					ft_print_button(*env, forward, pause);
				}
			}
			else
				ft_prev_map(env);
			refresh();
		}
	}
}

// 

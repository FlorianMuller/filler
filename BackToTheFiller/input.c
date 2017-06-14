/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 22:03:37 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/14 00:22:25 by fmuller          ###   ########.fr       */
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
		if (input == ERR || (/*pause == 1 &&*/ (input == KEY_RIGHT  || input == KEY_LEFT)))
		{
			if (forward)
				ft_next_map(env);
			else
				ft_prev_map(env);
			refresh();
		}
	}
}

// 

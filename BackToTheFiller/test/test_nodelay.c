/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nodelay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 03:23:34 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/11 05:27:52 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

void	ft_init_ncurses()
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	// nodelay(stdscr, TRUE);
	timeout(1000);
}

void	ft_set_speed(int speed, int pause)
{
	if (pause)
		timeout(-1);
	else if (speed == 1)
		timeout(0);
	else if (speed == 2)
		timeout(25);
	else if (speed == 3)
		timeout(100);
	else if (speed == 4)
		timeout(300);
	else if (speed == 5)
		timeout(1000);
}

int main()
{
	int		input;
	int 	speed = 5;
	int 	pause = 0;
	int		forward = 1;
	int		n = 0;


	ft_init_ncurses();
	mvprintw(LINES / 2, COLS / 2, "%d\n", n);
	refresh();
	while (1)
	{
		if ((input = getch()) != ERR)
		{
			if (input == '1')
				speed = 1;
			else if (input == '2')
				speed = 2;
			else if (input == '3')
				speed = 3;
			else if (input == '4')
				speed = 4;
			else if (input == '5')
				speed = 5;
			else if (input == ' ')
				pause = (pause == 0) ? 1 : 0;
			else if (input == KEY_RIGHT)
				forward = 1;
			else if (input == KEY_LEFT)
				forward = 0;
			else if (input == 'q')
			{
				curs_set(1);
				endwin();
				return (0);
			}
			else
				n = 0;
			ft_set_speed(speed, pause);
		}
		if (pause == 0 || input == KEY_RIGHT || input == KEY_LEFT)
		{
			if (input == KEY_RIGHT || forward)
				n++;
			else
				n--;
			mvprintw(LINES / 2, COLS / 2, "%d\n", n);
			refresh();
		}

	}

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 22:20:25 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/15 03:14:09 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"


int		ft_init_ncurses()
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	if (has_colors() == FALSE)
	{
		endwin();
		ft_printf("Your terminal does not support color\n");
		return (1);
	}
	start_color();
	curs_set(0);
	timeout(200);
	return (0);
}

void	ft_init_color()
{
	init_color(COLOR_YELLOW, 1000, 616, 0); 
 	init_color(COLOR_BLUE, 153, 158, 133);
	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	init_pair(2, COLOR_CYAN, COLOR_BLUE);
	init_pair(3, COLOR_RED, COLOR_BLUE);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_WHITE, COLOR_BLUE);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_CYAN, COLOR_BLACK);
}


void	ft_end_ncurses(int fd)
{
	curs_set(1);
	endwin();
	close(fd);
	printf("TOTO\n");
}

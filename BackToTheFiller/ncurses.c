/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 22:20:25 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/13 22:36:23 by fmuller          ###   ########.fr       */
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

void	ft_end_ncurses(int fd)
{
	curs_set(1);
	endwin();
	close(fd);
	printf("TOTO\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncur_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:53:52 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/09 16:34:06 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <ncurses.h>

void	number()
{
	int 	row;
	int		col;
	char	ch;
	int		n = 0;
	
	getmaxyx(stdscr, row, col);
	while (n < 5)
	{
		if (getch() == ' ')
		{
			mvprintw(row / 2, col / 2, "%d\n", n);
			refresh();
			// sleep(1);
		}
		n++;
	}
}

void	test_attr()
{
	int 	row;
	int		col;
	int		x;
	int		y;
	char	str[] = "Toto fait du velo";

	getmaxyx(stdscr, row, col);
	move((row - 11) / 2, (col - ft_strlen(str)) / 2);

	// Normnal
	printw("%s\n", str);

	// Standout
	attrset(A_STANDOUT);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// UNDERLINE
	attrset(A_UNDERLINE);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// REVERSE
	attrset(A_REVERSE);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// A_BLINK
	attrset(A_BLINK);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// A_DIM
	attrset(A_DIM);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// A_BOLD
	attrset(A_BOLD);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// A_PROTECT
	attrset(A_PROTECT);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// A_PROTECT
	attrset(A_PROTECT);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// A_INVIS
	attrset(A_INVIS);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// A_ALTCHARSET
	attrset(A_ALTCHARSET);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);

	// A_CHARTEXT
	attrset(A_CHARTEXT);
	getyx(stdscr, y, x);
	mvprintw(y, (col - ft_strlen(str)) / 2, "%s\n", str);
/*
    A_NORMAL        Normal display (no highlight)
    A_STANDOUT      Best highlighting mode of the terminal.
    A_UNDERLINE     Underlining
    A_REVERSE       Reverse video
    A_BLINK         Blinking
    A_DIM           Half bright
    A_BOLD          Extra bright or bold
    A_PROTECT       Protected mode
    A_INVIS         Invisible or blank mode
    A_ALTCHARSET    Alternate character set
    A_CHARTEXT      Bit-mask to extract a character
    COLOR_PAIR(n)   Color-pair number n 
*/
}

void	ft_test_windows()
{
	// WINDOW *my_win;
	// int	startx = 5;
	// int	starty= 5;
	// int	width = 3;
	// int	height = 10;

	// my_win = create_newwin(heigh, width, starty, startx);
	// return (0);
}

int		ft_init_ncurses()
{
	initscr();					//Start curses mode
	cbreak();					//Disable buffering of user input
	// raw();						//like cbreak() + disable ctrl+c..
	noecho();					//Disable echo
	keypad(stdscr, TRUE);		//Enable reading Function key
	if (has_colors() == FALSE)
	{
		endwin();
		ft_printf("Your terminal does not support color\n");
		return (1);
	}
	start_color();
	return (0);
}

int main()
{
	if (ft_init_ncurses())
		return (1);

	// number();
	test_attr();
	// ft_test_windows();

	getch();
	endwin();
	return (0);
}





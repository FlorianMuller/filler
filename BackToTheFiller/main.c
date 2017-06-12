/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:19:10 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/12 17:03:11 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"
#include <fcntl.h>

void	ft_passnline(size_t n)
{
	char *s;

	while (n != 0)
	{
		get_next_line(FD, &s);
		ft_strdel(&s);
		n--;
	}
}

int		ft_init_ncurses()
{
	initscr();
	cbreak();
	// noecho();
	keypad(stdscr, TRUE);
	if (has_colors() == FALSE)
	{
		endwin();
		ft_printf("Your terminal does not support color\n");
		return (1);
	}
	start_color();
	// curs_set(0);
	timeout(1000);
	return (0);
}

void	ft_end_ncurses()
{
	curs_set(1);
	endwin();
	printf("TOTO\n");
}

int		ft_input()
{
	// // int	input;

	// // input = getch();
	// if (input == 'q' || input == 'Q')
	// 	return(1);
	// return (0);

	char	s[2];

	read(3, &s, 1);
	s[1] = '\0';
	if (s[0] == 'q' || s[0] == 'Q')
		return(1);
	return (0);
}

void	ft_while(t_env *env)
{
	int	forward;
	int	pause;
	int	speed;

	forward = 1;
	pause = 0;
	speed = 5;

	int n = 0;
	while (n < 10)
	{
		if (ft_input())
			break;
		ft_next_map(env);
		refresh();
		n++;
		// sleep(1);
	}
}

int main()
{
	t_env	env;
	char	*s;

	// freopen("/dev/tty", "rw", stdin);

	// FILE *new = fdopen(3, "rw");
	// freopen("/dev/tty", "rw", new);

	open("log_vm.txt", O_RDWR);

	printf("YEAH\n");
	// if (ft_init_ncurses())
		// return (1);
	ft_init_all(&env);
	
	ft_while(&env);
	
	while (get_next_line(FD, &s) == 1)
	{
		ft_strdel(&s);
	}
	ft_end_ncurses();
	return (0);
}

/*
//Old Main 4 test

while (1)
	{
		printf("\n");
		if (ft_next_map(&env))
			break;
	}

	sleep(3);
	printf("\n");
	
	while (1)
	{
		printf("\n");
		if (ft_prev_map(&env))
			break;
	}
*/

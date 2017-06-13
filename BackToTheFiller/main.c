/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:19:10 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/13 18:54:43 by fmuller          ###   ########.fr       */
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

int		ft_input(int *forward, int *speed, int *pause)
{
	int	input;

	input = getch();
	if (input == 'q' || input == 'Q')
		return(1);
	else if (input == '1')
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
	return (0);

	//= = = = = = = 
	// char	s[2];

	// read(3, &s, 1);
	// s[1] = '\0';
	// if (s[0] == 'q' || s[0] == 'Q')
	// 	return(1);
	// return (0);
}

void	ft_while(t_env *env)
{
	int	forward;
	int	speed;
	int	pause;

	forward = 1;
	speed = 200;
	pause = 0;

	while (1)
	{
		if (ft_input(&forward, &speed, &pause))
			break;
		if (forward)
			ft_next_map(env);
		else
			ft_prev_map(env);
		refresh();
	}
}

int main()
{
	t_env	env;
	// char	*s;
	int		fd;

	// freopen("/dev/tty", "rw", stdin);

	// FILE *new = fdopen(3, "rw");
	// freopen("/dev/tty", "rw", new);

	// printf ("fd : %d\n", open("log_vm.txt", O_RDWR));

	mknod("coolpipe", S_IFIFO | 0666, 0);
	fd = open("coolpipe", O_RDONLY);

	// printf("TOTO\n");
	// printf ("fd : %d\n", open("superpipe3", O_RDONLY));
	// printf("BATEAU\n");

	if (ft_init_ncurses())
		return (1);
	ft_init_all(&env);
	
	ft_while(&env);
	
	// while (get_next_line(FD, &s) == 1)
	// {
	// 	ft_strdel(&s);
	// }
	ft_end_ncurses(fd);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 00:25:01 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/15 01:57:49 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"

void	ft_print_title()
{
	// init_pair(6, COLOR_WHITE, COLOR_BLACK);
	attron(A_BOLD);
	// attron(COLOR_PAIR(6));
	mvprintw(Y_TITLE, 0, " _____         _   _____     _____ _       _____ _ _ _         \n| __  |___ ___| |_|_   _|___|_   _| |_ ___|   __|_| | |___ ___ \n| __ -| .'|  _| '_| | | | . | | | |   | -_|   __| | | | -_|  _|\n|_____|__,|___|_,_| |_| |___| |_| |_|_|___|__|  |_|_|_|___|_|  ");
	attrset(A_NORMAL);

	init_pair(6, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(6));
	printw("by fmuller\n");
	attroff(COLOR_PAIR(6));
}

// void	ft_create_alph(char (*)alph[4][94])
// {
// 	// char	alph[5][94];

// 	ft_strcpy(*alph[0], "                      _                                                                      ");
// 	ft_strcpy(*alph[1], "  _. |_   _  _|  _  _|_  _  |_  o o |  | ._ _  ._   _  ._   _. ._  _ _|_                   _ ");
// 	ft_strcpy(*alph[2], " (_| |_) (_ (_| (/_  |  (_| | | | | |< | | | | | | (_) |_) (_| |  _>  |_ |_| \\/ \\/\\/ >< \\/ /_");
// 	ft_strcpy(*alph[3], "                         _|      _|                    |     |                          /    ");
// }

void	ft_print_letter(int y, char letter)
{
	char	big_alph[4][94];
	char	alph[27];
	int		big_alph_len[26];
	int		i;
	int		j;

	i = 0;
	j = 0;
	// ft_create_alph(&big_alph);
	ft_strcpy(big_alph[0], "                      _                                                                      ");
	ft_strcpy(big_alph[1], "  _. |_   _  _|  _  _|_  _  |_  o o |  | ._ _  ._   _  ._   _. ._  _ _|_                   _ ");
	ft_strcpy(big_alph[2], " (_| |_) (_ (_| (/_  |  (_| | | | | |< | | | | | | (_) |_) (_| |  _>  |_ |_| \\/ \\/\\/ >< \\/ /_");
	ft_strcpy(big_alph[3], "                         _|      _|                    |     |                          /    ");
	ft_strcpy(alph, "abcdefghijklmnopqrstuvwxyz");
	while (alph[i] != letter)
	{
		j += big_alph_len[i];
		i++;
	}
	printw("%.*s", big_alph_len[i], big_alph[y] + j);
}

void	ft_print_name(t_env *env)
{
	timeout(-1);
	t_point	p;
	char	vs[41];

	ft_strcpy(vs, "       __ \n \\  / (_  \n  \\/  __) \n          ");
	p.y = 0;
	while (p.y < 4)
	{
		p.x = 0;
		move(Y_NAME + p.y, 0);
		while (p.x < (int)ft_strlen(env->p1) + (int)ft_strlen(env->p2) + 1)
		{
	printw("y: %d | x: %d\n", p.y, p.x);
	getch();
			if (p.x > (int)ft_strlen(env->p1) + 1)
				ft_print_letter(p.y, env->p2[p.x - ft_strlen(env->p1) + 1]);
			else if (p.x > (int)ft_strlen(env->p1))
				printw("%.10s", vs + (p.y * 10));
			else
				ft_print_letter(p.y, env->p1[p.x]);
			p.x++;
		}
		p.y++;
	}
	timeout(400);
}

/*
       __ 
 \  / (_  
  \/  __) 
          

       __  \  / (_    \/  __)           
*/

void	ft_first_print(t_env *env)
{
	ft_print_title();
	ft_print_name(env);
	(void)env;
}
/*

                      _                                                                      
  _. |_   _  _|  _  _|_  _  |_  o o |  | ._ _  ._   _  ._   _. ._  _ _|_                   _ 
 (_| |_) (_ (_| (/_  |  (_| | | | | |< | | | | | | (_) |_) (_| |  _>  |_ |_| \/ \/\/ >< \/ /_
                         _|      _|                    |     |                          /    
a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
4, 4, 3, 4, 4, 4, 4, 4, 2, 2, 3, 2, 6, 4, 4, 4, 4, 3, 3, 4, 4, 3, 5, 3, 3, 3

= 93

*/
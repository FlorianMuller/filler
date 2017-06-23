/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 00:25:01 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/23 17:31:29 by fmuller          ###   ########.fr       */
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
	int		big_alph_len[26] = {4, 4, 3, 4, 4, 4, 4, 4, 2, 2, 3, 2, 6, 4, 4, 4, 4, 3, 3, 4, 4, 3, 5, 3, 3, 3};
	int		i;
	int		j;

	i = 0;
	j = 0;
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
	t_point	p;
	char	vs[45];

	ft_strcpy(vs, "        __   \\  / (_     \\/  __)            ");
	p.y = 0;
	while (p.y < 4)
	{
		p.x = 0;
		move(Y_NAME + p.y, 0);
		while (p.x < (int)ft_strlen(env->p1) + (int)ft_strlen(env->p2) + 1)
		{
			if (p.x >= (int)ft_strlen(env->p1) + 1)
			{
				attron(COLOR_PAIR(8));
				ft_print_letter(p.y, env->p2[p.x - (ft_strlen(env->p1) + 1)]);
			}
			else if (p.x >= (int)ft_strlen(env->p1))
			{
				attrset(A_NORMAL);
				printw("%.11s", vs + (p.y * 11));
			}
			else
			{
				attron(COLOR_PAIR(7));
				ft_print_letter(p.y, env->p1[p.x]);
			}

			p.x++;
		}
		p.y++;
	}
}

/*
012345678901234  
fmuller|cpoulet
       __ 
 \  / (_  
  \/  __) 
          

       __  \  / (_    \/  __)           
*/

void	ft_first_print(t_env *env)
{
	ft_print_title();
	ft_print_name(env);
	ft_print_button(*env, 1, 0);
	ft_print_speed(*env, '3');
	mvprintw(Y_MAP + env->map_size.y + 9, 0, "[Q]       = Quit\n[cmd +/-] = Zoom");
}
/*

                      _                                                                      
  _. |_   _  _|  _  _|_  _  |_  o o |  | ._ _  ._   _  ._   _. ._  _ _|_                   _ 
 (_| |_) (_ (_| (/_  |  (_| | | | | |< | | | | | | (_) |_) (_| |  _>  |_ |_| \/ \/\/ >< \/ /_
                         _|      _|                    |     |                          /    
a,q b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
4, 4, 3, 4, 4, 4, 4, 4, 2, 2, 3, 2, 6, 4, 4, 4, 4, 3, 3, 4, 4, 3, 5, 3, 3, 3

= 93

*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 00:25:01 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/11 20:07:21 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "back_to_the_filler.h"

void	ft_print_title(void)
{
	attron(A_BOLD);
	mvprintw(Y_TITLE, 0, " _____         _   _____     _____ _       _____ _ _ \
_         \n| __  |___ ___| |_|_   _|___|_   _| |_ ___|   __|_| | |___ ___ \n| \
__ -| .'|  _| '_| | | | . | | | |   | -_|   __| | | | -_|  _|\n|_____|__,|___|_\
,_| |_| |___| |_| |_|_|___|__|  |_|_|_|___|_|  ");
	attrset(A_NORMAL);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(6));
	printw("by fmuller\n");
	attroff(COLOR_PAIR(6));
}

void	ft_print_letter(int y, char letter)
{
	char	big_alph[4][94];
	char	alph[27];
	int		i;
	int		j;
	int		big_alph_len[26];

	i = 0;
	j = 0;
	ft_nbcpy(big_alph_len, 26, 4, 4, 3, 4, 4, 4, 4, 4, 2, 2, 3,
	2, 6, 4, 4, 4, 4, 3, 3, 4, 4, 3, 5, 3, 3, 3);
	ft_strcpy(big_alph[0], "                      \
_                                                                      ");
	ft_strcpy(big_alph[1], "  _. |_   _  _|  _  _|_  _  |_  o o |  | ._ _  .\
_   _  ._   _. ._  _ _|_                   _ ");
	ft_strcpy(big_alph[2], " (_| |_) (_ (_| (/_  |  (_| | | | | |< | | | | | \
| (_) |_) (_| |  _>  |_ |_| \\/ \\/\\/ >< \\/ /_");
	ft_strcpy(big_alph[3], "                         _|      \
_|                    |     |                          /    ");
	ft_strcpy(alph, "abcdefghijklmnopqrstuvwxyz");
	while (alph[i] != letter)
	{
		j += big_alph_len[i];
		i++;
	}
	printw("%.*s", big_alph_len[i], big_alph[y] + j);
}

void	ft_print_name2(t_env *env, t_point p, char vs[45])
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
			ft_print_name2(env, p, vs);
			p.x++;
		}
		p.y++;
	}
}

void	ft_first_print(t_env *env)
{
	ft_print_title();
	ft_print_name(env);
	ft_print_button(*env, 1, 0);
	ft_print_speed(*env, '3');
	mvprintw(Y_MAP + env->map_size.y + 9, 0,
		"[cmd + C] = Quit\n[cmd +/-] = Zoom");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:46:28 by fmuller           #+#    #+#             */
/*   Updated: 2017/09/11 20:07:24 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "back_to_the_filler.h"

void	ft_print_first_map_line(t_env env)
{
	int	n;
	int	num;

	n = 0;
	num = 0;
	attrset(A_NORMAL);
	move(Y_FIRST_MAP_LINE, 8);
	while (n < env.map_size.x && n + 8 < COLS)
	{
		if (!(n % 10))
			num = 0;
		printw("%d ", num);
		n++;
		num++;
	}
}

void	ft_map_color(char **map, t_point p)
{
	if (map[p.y][p.x] == 'O')
		attron(COLOR_PAIR(1));
	else if (map[p.y][p.x] == 'X')
		attron(COLOR_PAIR(2));
	else if (map[p.y][p.x] == 'o')
		attron(COLOR_PAIR(3));
	else if (map[p.y][p.x] == 'x')
		attron(COLOR_PAIR(4));
	else if (!ft_isdigit(map[p.y][p.x]))
		attron(COLOR_PAIR(5));
}

void	ft_print_map(char **map)
{
	t_point	p;
	t_point	max;

	p.x = 0;
	p.y = 0;
	getmaxyx(stdscr, max.y, max.x);
	while (map[p.y])
	{
		move(Y_MAP + p.y, 3);
		while (map[p.y][p.x])
		{
			ft_map_color(map, p);
			if ((p.x * 2) + 4 < COLS)
				printw("%c", map[p.y][p.x]);
			if ((p.x * 2) + 4 < COLS && !(ft_isdigit(map[p.y][p.x]) &&
				map[p.y][p.x + 1] != ' ') && map[p.y][p.x] != ' ')
				printw(" ");
			attrset(A_NORMAL);
			p.x++;
		}
		p.y++;
		p.x = 0;
	}
	printw("\n");
}

void	ft_print_button(t_env env, int forward, int pause)
{
	t_point	p;

	attrset(A_NORMAL);
	p.y = Y_MAP + env.map_size.y + 1;
	p.x = ((((env.map_size.x * 2 + 1) - 28) / 2) + 7);
	mvprintw(p.y, 0,
"                                                                        ");
	if (!forward)
		attron(COLOR_PAIR(9));
	mvprintw(p.y, p.x, " // ");
	mvprintw(p.y + 1, p.x, " \\\\ ");
	attrset(A_NORMAL);
	p.x += 4;
	mvprintw(p.y, p.x, "         %s         ", ((pause == 0) ? "||" : "|\\"));
	mvprintw(p.y + 1, p.x, "         %s         ",
		((pause == 0) ? "||" : "|/"));
	p.x += 20;
	if (forward)
		attron(COLOR_PAIR(9));
	mvprintw(p.y, p.x, " \\\\ ");
	mvprintw(p.y + 1, p.x, " // ");
	attrset(A_NORMAL);
	mvprintw(p.y + 3, ((((env.map_size.x * 2 + 1) - 43) / 2) + 7),
		"[LeftArrow]      [Space]       [RightArrow]");
}

void	ft_resize(t_env *env)
{
	clear();
	ft_print_title();
	ft_print_name(env);
	ft_print_first_map_line(*env);
	ft_print_map(env->map_list->map);
	if (env->end)
	{
		attron(COLOR_PAIR(6));
		mvprintw(Y_MAP + env->map_size.y + 9, 0, "[Q]       = Quit\n");
		attroff(COLOR_PAIR(6));
		printw("[cmd +/-] = Zoom");
	}
	else
		mvprintw(Y_MAP + env->map_size.y + 9, 0,
			"[cmd + C] = Quit\n[cmd +/-] = Zoom");
}

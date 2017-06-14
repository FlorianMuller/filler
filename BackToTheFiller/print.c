/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 00:25:01 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/14 01:14:11 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backToTheFiller.h"

void	print_title()
{
	// init_pair(6, COLOR_WHITE, COLOR_BLACK);
	attron(A_BOLD);
	// attron(COLOR_PAIR(6));
	printw("%s");
	attrset(A_NORMAL);

	init_pair(6, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(6));
	printw("by fmuller\n");
	attroff(COLOR_PAIR(6));
}
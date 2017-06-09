/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:55 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/06 19:02:05 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <curses.h>

// 0x1B

void	ft_fake_download()
{
	int	time;

	time = 0;
	ft_printf("{red}Downoading{eoc} [\n");
	ft_printf("\x1B[1A"); //Up 1
	ft_printf("\x1B[13C"); // Right 12
	while (time < 10)
	{
		ft_printf("\x1B[1D"); // Left 1
		ft_printf("{green}={eoc}");
		ft_printf("]");
		sleep(1);
		time++;
	}
	ft_printf("\n");
	
}

int main(int argc, char const *argv[])
{
	int	n;
	int	i = 0;
	// ft_printf("\x1B[?25l"); //Hide Cursor
	
	ft_printf("\x1B[2J"); //clean screen
	while (1)
	{
		ft_printf("\x1B[H"); // cursor home
		n = 0;
		while (n < 4)
		{
			ft_printf("%d\n", i);
			n++;
		}
		i++;
		sleep(1);
	}
	ft_printf("\x1B[?25h"); //Show Cursor
	return 0;
}

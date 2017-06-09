/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 21:21:07 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/09 17:01:34 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <ncurses.h>

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
	start_color();				//Enable color
	curs_set(0);
	return (0);
}

void	ft_init_all_color()
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
}

void	ft_print_title()
{
	// char title[] = " _         ___   ___       __               \n|_) _  _ |  |  _  | |_  _ |_  o  |  |  _  __\n|_)(_|(_ |< | (_) | | |(/_|   |  |  | (/_ | ";
	char	title[] = " _____         _   _____     _____ _       _____ _ _ _         \n| __  |___ ___| |_|_   _|___|_   _| |_ ___|   __|_| | |___ ___ \n| __ -| .'|  _| '_| | | | . | | | |   | -_|   __| | | | -_|  _|\n|_____|__,|___|_,_| |_| |___| |_| |_|_|___|__|  |_|_|_|___|_|  ";
	
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	attron(A_BOLD);
	attron(COLOR_PAIR(7));
	printw("%s", title);
	attrset(A_NORMAL);

	init_pair(6, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(6));
	printw("by fmuller\n");
	attrset(A_NORMAL);
}

void	ft_print_player()
{
	// int x, y;

	// attron(COLOR_PAIR(1));
	// getyx(stdscr, y, x);
	// mvprintw(y, 10,"[fmuller]");
	// attrset(A_NORMAL);
	
	// printw("    VS    ");
	
	// attron(COLOR_PAIR(2));
	// printw("[carly]");
	// attrset(A_NORMAL);
	
	// printw("\n\n");
	
	/*= = = = = == */
	
	// printw("   _\n _|_ ._ _      | |  _  ._   \\  / (_     _  _. ._ | o o\n  |  | | | |_| | | (/_ |     \\/  __)   (_ (_| |  | | |\n                                                    _|\n\n");
	int x, y;

	getyx(stdscr, y, x);

	init_pair(8, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(8));
	mvprintw(y + 0, 0, "   _");
	mvprintw(y + 1, 0, " _|_ ._ _      | |  _  ._");
	mvprintw(y + 2, 0, "  |  | | | |_| | | (/_ |");
	attrset(A_NORMAL);

	mvprintw(y + 1, 30, "\\  / (_");
	mvprintw(y + 2, 30, " \\/  __)");

	init_pair(9, COLOR_CYAN, COLOR_BLACK);
	attron(COLOR_PAIR(9));
	mvprintw(y + 1, 41, " _  _. ._ | o o");
	mvprintw(y + 2, 41, "(_ (_| |  | | |");
	mvprintw(y + 3, 41, "             _|");
	attrset(A_NORMAL);

	printw("\n");
}

/*

   _                     
 _|_ ._ _      | |  _  ._   \  / (_     _  _. ._ | o o
  |  | | | |_| | | (/_ |     \/  __)   (_ (_| |  | | |
                                                    _|

*/

void	ft_print_map()
{
	char	map[] = "        0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6\n   000  . . . . o o O O O O O O . . . . .\n   001  . . . . . o . . . O O O O O O . .\n   002  . . . . . . . . . . O O O O O O O\n   003  . . . . . . . . O O O O O O O O O\n   004  . . . . . . . . . O O O X X X X X\n   005  . . . . . . . . . O O O X X X X X\n   006  . . . . . . . . . O O O X X X X X\n   007  . . . . O . . . O O O O X X X X X\n   008  . . O O O O O . O O O X X X X X X\n   009  . . . . . O O O O O O X X X X X X\n   010  . . . . O O O O O O O O X X X X X\n   011  . . . O O O O X X X X X X X X X X\n   012  . . O O O O X X X X X X X X X X X\n   013  . . O O O O O X X X X X X X X X X\n   014  . . O O O O X X X X X X X X X x x\n";
	int		i = 0;

	while (map[i] != '\n')
	{
		printw("%c", map[i]);
		i++;
	}
	while (map[i])
	{
		if (map[i] == 'O' || map[i] == 'o')
		{
			if (map[i] == 'o')
				attron(COLOR_PAIR(5));
			else
				attron(COLOR_PAIR(1));
		}
		else if (map[i] == 'X' || map[i] == 'x')
		{
			if (map[i] == 'x')
				attron(COLOR_PAIR(5));
			else
				attron(COLOR_PAIR(2));
		}
		else if (map[i] == '.')
			attron(COLOR_PAIR(3));
		else
			attron(COLOR_PAIR(4));
		printw("%c", map[i]);
		attrset(A_NORMAL);
		if (map[i] == '\n' && map[i + 1] != '\0')
		{
			i++;
			printw("%c", map[i]);
			i++;
			printw("%c", map[i]);
			i++;
			printw("%c", map[i]);
			i++;
			printw("%c", map[i]);
			i++;
			printw("%c", map[i]);
			i++;
			printw("%c", map[i]);
			i++;
			printw("%c", map[i]);
			i++;
			printw("%c", map[i]);
		}
		i++;
	}
	printw("\n");
}
/*
//   |\  | |    \\
\\   |/  | |    //
*/
void	ft_print_usage()
{
	//         014  . . O O O O X X X X X X X X X x x
	// printw("         <<Backward   Pause    Forward>>\n");
	// printw("             <<         ||         >>\n");
	printw("           //      |\\  ||       \\\\\n");
	printw("           \\\\      |/  ||       //\n\n");
	printw("      [LeftArrow]  [Space]  [RightArrow]\n");
	// printw("                     [1 - 5]\n");
	// printw("                      Speed\n");
	// printw("[1 - 5] = Speed\n");
	// printw("[Esc]   = Quit\n");
	// printw("--------------------------------------------------\n");
	printw("      __________________________________\n");
	printw("      [1 - 5] = Speed       [Esc] = Quit\n");

}

int main(int argc, char const *argv[])
{
	if (ft_init_ncurses())
		return (1);

	// ft_init_all_color();
	// init_pair(1, COLOR_CYAN, COLOR_BLACK);
	// init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	// init_pair(3, COLOR_GREEN, COLOR_BLACK);
	// init_pair(4, COLOR_WHITE, COLOR_BLACK);

	init_color(COLOR_YELLOW, 1000, 616, 0);
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_BLUE, 153, 158, 133);
	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	init_pair(2, COLOR_CYAN, COLOR_BLUE);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_RED, COLOR_BLUE);
	
	ft_print_title();
	ft_print_player();
	ft_print_map();
	ft_print_usage();
	refresh();

	// getch();
	// init_pair(1, COLOR_RED, COLOR_BLACK);
	// init_pair(2, COLOR_BLUE, COLOR_BLACK);
	// init_pair(3, COLOR_WHITE, COLOR_BLACK);
	// init_pair(4, COLOR_WHITE, COLOR_BLACK);
	// refresh();


	getch();
	init_color(COLOR_GREEN, 651, 886, 176);
	init_pair(2, COLOR_GREEN, COLOR_BLUE);
	refresh();

	getch();
	curs_set(1);
	endwin();
	return (0);
}















































/* 
Rectangles
 _____         _   _____     _____ _       _____ _ _ _         
| __  |___ ___| |_|_   _|___|_   _| |_ ___|   __|_| | |___ ___ 
| __ -| .'|  _| '_| | | | . | | | |   | -_|   __| | | | -_|  _|
|_____|__,|___|_,_| |_| |___| |_| |_|_|___|__|  |_|_|_|___|_|  

BigFig
 _         ___   ___       __               
|_) _  _ |  |  _  | |_  _ |_  o  |  |  _  __
|_)(_|(_ |< | (_) | | |(/_|   |  |  | (/_ | 

Chunky
 ______              __     _______         _______ __           _______ __ __ __             
|   __ \.---.-.----.|  |--.|_     _|.-----.|_     _|  |--.-----.|    ___|__|  |  |.-----.----.
|   __ <|  _  |  __||    <   |   |  |  _  |  |   | |     |  -__||    ___|  |  |  ||  -__|   _|
|______/|___._|____||__|__|  |___|  |_____|  |___| |__|__|_____||___|   |__|__|__||_____|__|  

Big
 ____             _ _______ _______ _          ______ _ _ _           
 |  _ \           | |__   __|__   __| |        |  ____(_) | |          
 | |_) | __ _  ___| | _| | ___ | |  | |__   ___| |__   _| | | ___ _ __ 
 |  _ < / _` |/ __| |/ / |/ _ \| |  | '_ \ / _ \  __| | | | |/ _ \ '__|
 | |_) | (_| | (__|   <| | (_) | |  | | | |  __/ |    | | | |  __/ |   
 |____/ \__,_|\___|_|\_\_|\___/|_|  |_| |_|\___|_|    |_|_|_|\___|_|   

 Cricket
  _______            __    _______       _______ __          _______ __ __ __            
 |   _   .---.-.----|  |--|       .-----|       |  |--.-----|   _   |__|  |  .-----.----.
 |.  1   |  _  |  __|    <|.|   | |  _  |.|   | |     |  -__|.  1___|  |  |  |  -__|   _|
 |.  _   |___._|____|__|__`-|.  |-|_____`-|.  |-|__|__|_____|.  __) |__|__|__|_____|__|  
 |:  1    \                 |:  |         |:  |             |:  |                        
 |::.. .  /                 |::.|         |::.|             |::.|                        
 `-------'                  `---'         `---'             `---'                        

Efti Italic
   ___            _____   _____        ____            
  / o.) _   __ /7/_  _/_ /_  _//7  __ / __/()/7/7 __ _ 
 / o \,'o|,','//_7/ /,'o| / / / \,'o// _/ /7////,'o///7
/___,'|_,7\_\//\\/_/ |_,'/_/ /n_/|_(/_/  ////// |_(//  

Ivrit
  ____             _    _____   _____ _          _____ _ _ _           
 | __ )  __ _  ___| | _|_   _|_|_   _| |__   ___|  ___(_) | | ___ _ __ 
 |  _ \ / _` |/ __| |/ / | |/ _ \| | | '_ \ / _ \ |_  | | | |/ _ \ '__|
 | |_) | (_| | (__|   <  | | (_) | | | | | |  __/  _| | | | |  __/ |   
 |____/ \__,_|\___|_|\_\ |_|\___/|_| |_| |_|\___|_|   |_|_|_|\___|_|   

 JS Stick Letter
 __        __       ___  __  ___       ___  ___              ___  __  
|__)  /\  /  ` |__/  |  /  \  |  |__| |__  |__  | |    |    |__  |__) 
|__) /~~\ \__, |  \  |  \__/  |  |  | |___ |    | |___ |___ |___ |  \ 

Mini
  _           ___   ___         _              
 |_)  _.  _ |  |  _  | |_   _  |_ o | |  _  ._ 
 |_) (_| (_ |< | (_) | | | (/_ |  | | | (/_ |  

Straight
 __        ___ ___      __       
|__) _  _|  | _ | |_  _|_.|| _ _ 
|__)(_|(_|( |(_)| | )(-| |||(-|  

= = = = = == = = = = == = = 

 _____         _       / /            
| __  |___ ___| |_    / / _____ _____ 
| __ -| .'|  _| '_|  < < |_____|_____|
|_____|__,|___|_,_|   \ \|_____|_____|
 _____        _____ _ _\_\            
|_   _|___   |   __|_| | |___ ___     
  | | | . |  |   __| | | | -_|  _|    
 _|_|_|___|  |__|  |_|_|_|___|_|      
|_   _| |_ ___                        
  | | |   | -_|                       
  |_| |_|_|___|                       

  _____         _       / /            
| __  |___ ___| |_    / / _____ _____ 
| __ -| .'|  _| '_|  < < |_____|_____|
|_____|__,|___|_,_|   \ \|_____|_____|
 _____                 \ \            
|_   _|___                            
  | | | . |      _____ _ _ _                       
 _|_|_|___|     |   __|_| | |___ ___                           
|_   _| |_ ___  |   __| | | | -_|  _|                         
  | | |   | -_| |__|  |_|_|_|___|_|                            
  |_| |_|_|___|                       
*/








/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_sokoban.h"

static const char *color_flag = "--colors";

int main (int ac, char **av)
{
	char **map = NULL;
	player_t player = NULL;
	box_t boxes = NULL;

	if (ac < 2)
		my_put_exit("Invalid arguments use ./my_sokoban -h\n", 39, 84);
	if (av[1][0] == '-' && av[1][1] == 'h')
		h_flag_disp();
	map = ini_sokoban(av[1]);
	if (!map || check_map(map) == -1)
		my_put_exit("Invalid map or unable to open it.\n",35, 84);
	ini_game_n_color(av[2]);
	ini_ressources (map, &player, &boxes);
	while (manage_screen(map, player, boxes) == 0)
		endwin();
	free_boxes(boxes);
	free_map(map);
	my_put_exit("You Win !\n", 10, 0);
	return (0);
}
void ini_game_n_color(char *flag)
{
	initscr();
	if (flag && my_strcmp(flag, (char*)color_flag) == 1)
		start_color();
	init_pair(1 , COLOR_YELLOW, COLOR_YELLOW);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_WHITE, COLOR_GREEN);
	init_pair(4, COLOR_CYAN, COLOR_CYAN);
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
}

void ini_ressources (char **map, player_t *player, box_t *boxes)
{
	*player = ini_player(map);
	*boxes = ini_boxes(map);
}

void h_flag_disp (void)
{
	write(1, "USAGE :\n\n", 9);
	write(1, "./my_sokoban [-h]  : Display this help message\n", 47);
	write(1, "             [map] : play selected map\n", 40);
	write(1, "             [map --colors] : same but with colors\n\n", 53);
	write(1, "DESCRIPTION :\n\n", 16);
	write(1, "my_sokoban is a game where you have to put 'X' where 'O' are.\n"
	      , 63);
	write(1, "You are the 'P' and you can move with arrow keys\n\n", 51);
	exit(0);
}

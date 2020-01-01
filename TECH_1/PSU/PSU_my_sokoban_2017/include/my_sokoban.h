/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef _MY_SOKOBAN_H_
#define _MY_SOKOBAN_H_

#define NOT_OBJECTS(x) (x != 'P' && x != 'X' && x != ' ' && x != 'O')
#define IS_O(x) (x == 'O')
#define IS_GROUND(x) (x == 'P' || x == 'X' || x == ' ')
#define PRINTABLE(x) (x == '#' || x == ' ' || x == '\n' || x == 'X' || x == 'O' || x == 'P')

typedef struct vector_s {
	int x;
	int y;
} vector_t;

typedef struct player_s {
	vector_t ori_pos;
	vector_t pos;
} *player_t;

typedef struct box_s {
	vector_t ori_pos;
	vector_t pos;
	int is_stuck_x;
	int is_stuck_y;
	int is_ok;
	struct box_s *next;
} *box_t;

char **ini_sokoban (char *path);
int count_n_line (FILE *file);
void free_map (char **map);
int manage_input (box_t boxes, player_t player, char **map);
void print_map (char **map);
vector_t get_pos(char **map, char who);
int manage_screen (char **map, player_t player, box_t boxes);
void reset_map(box_t boxes, player_t player);
void player_pos (player_t player);
void ini_game_n_color(char *);
player_t ini_player (char **map);
void print_player (player_t player);
void cols_right (box_t boxes, player_t player, char **map);
void cols_left (box_t boxes, player_t player, char **map);
void cols_up (box_t boxes, player_t player, char **map);
void cols_down (box_t boxes, player_t player, char **map);
void free_boxes (box_t boxes);
box_t fill_box (box_t boxes, int x, int y);
box_t ini_boxes (char **map);
void print_boxes (box_t boxes);
void ini_ressources (char **, player_t *, box_t*);
int my_strcmp (char * str1, char *str2);
void h_flag_disp (void);
void check_box_stuck (box_t boxes, char **map);
void check_box_ok (box_t boxes, char **map);
int check_win (box_t boxes);
int check_map (char **map);
void my_put_exit (char *message, int len, int re_val);
int check_stuck (box_t boxes);
#endif

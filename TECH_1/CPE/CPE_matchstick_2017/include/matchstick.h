/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "my_garbage_collector.h"

#ifndef _MATCHSTICK_
#define _MATCHSTICK_
int my_putstr (const char *str);
char **ini_board (int size);
int my_getnbr (char *str);
int my_putchar (int c);
int player_turn (char **board, int line_nb, int);
int can_remove_match (char *line, int nb, int max_stick);
int my_strlen(const char *str);
void my_put_2d_array(char **);
char **remove_match(char **, int, int);
int check_win (char **);
int ai_turn(char **, int, int);
int my_putnbr (int nb);
int is_str_num (const char *str);
void free_board(char **board);
int ai_win (char **board);
int player_win(char **board);
void too_much_sticks (int max_stick);
#endif

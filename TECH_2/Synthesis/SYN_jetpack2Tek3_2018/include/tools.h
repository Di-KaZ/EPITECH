/*
** EPITECH PROJECT, 2019
** temp_jetpack
** File description:
** tools
*/

#include <stdio.h>
#include <ctype.h>

#pragma once

int is_alpha_str(const char *str);

#define PRINT_ERROR_MSG_N_RETUN(x, y)\
    dprintf(2, "\x1b[31m[ERROR]\x1b[0m\t%s\n", x); return (y)
#define PRINT_INFO_MSG(x) printf("\x1b[36m[INFO]\x1b[0m\t%s\n", x)
#define ERR_ARG "Wrong argument, please check -h."
#define HELP "./serverJ2T3 -p <port> -g <gravity> -m <map>"

#define ERR_SELECT "Unable to bind select.\n"
#define ERR_ACCEPT "Unable to accept client request.\n"
#define ERR_EXEC_CMD "Unable to execute requested command.\n"
#define ERR_BIND "Unable to bind socket.\n"
#define ERR_SOCK "Unable to create socket.\n"
#define ERR_LISTEN "Unable to listen.\n"
#define ERR_BAD_MAP "Map dimention are invalid or bad character"

#define INFO_MAP_GOOD "Sucessfuly loaded map"
#define INFO_CON_CLI "Connection from : %s:%d.\n"
#define INFO_WRONG_MAP "Map file is invalid please check path and content"
#define INFO_MAP_CHAR1 "Map can only contains "
#define INFO_MAP_CHAR2 "'_'(empty) 'e'(electric fence) 'c'(coin)"
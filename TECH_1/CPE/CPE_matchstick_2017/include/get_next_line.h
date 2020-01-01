/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_garbage_collector.h"
#ifndef READ_SIZE
#	define READ_SIZE 1
#endif

char *get_next_line (int fd);

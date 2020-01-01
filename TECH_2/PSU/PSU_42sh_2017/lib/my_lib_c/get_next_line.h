/*
** EPITECH PROJECT, 2018
** get_next_line.h
** File description:
** get_next_line function declaration
*/

#ifndef READ_SIZE

#include <stdlib.h>
#include <unistd.h>

#define READ_SIZE (1)

char *get_next_line(int);

typedef struct pack_s pack_t;

struct pack_s {
	char buffer[READ_SIZE];
	int start;
	int size;
};

#endif

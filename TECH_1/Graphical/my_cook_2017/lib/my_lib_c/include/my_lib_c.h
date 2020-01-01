/*
** EPITECH PROJECT, 2018
** my_lib_c
** File description:
** my_lib_c
*/

#ifndef _MY_LIB_C_
#define _MY_LIB_C_
//includes
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef READ_SIZE
#	define READ_SIZE 1
#endif
//Prototypes
void *g_malloc (size_t size);
int my_getnbr (char const *str);
int my_putnbr (int nb);
int my_strcmp (char const *str1, char const *str2);
char **my_str_to_word_array (const char *str);
char *get_next_line (const int fd);
int my_strlen (const char *str);
int my_putchar (const int c);
int my_putstr (const char *str);
void my_put_2d_char (const char **array);
#endif

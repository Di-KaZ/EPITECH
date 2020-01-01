/*
** EPITECH PROJECT, 2018
** my_lib_c
** File description:
** include of my_lib_c
*/

#ifndef _MY_LIB_C_
#define _MY_LIB_C_
//includes
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#ifndef READ_SIZE
#	define READ_SIZE 20
#endif
//define
#define CHAR2INT(x) (x == 0 ? 0 : x - '0')
#define INT2CHAR(x) (x + '0')
#define IS_NUM(x) (x >= '0' && x <= '9')
#define IS_CAPS(x) (x >= 'A' && x <= 'Z')
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
char *my_strcpy (const char *str);
int is_str_num (const char *str);
int my_strfind (char const *str, char const *to_find);
int print_int (va_list args);
int print_string (va_list args);
int print_char (va_list args);
int print_percent (va_list args);
int my_printf (char *, ...);
int my_random (void);
char *my_strcat (char *, char *);
#endif

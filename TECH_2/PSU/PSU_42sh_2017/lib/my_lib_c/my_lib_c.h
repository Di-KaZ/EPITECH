/*
** EPITECH PROJECT, 2018
** my_lib_c
** File description:
** all usual fuction for C
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
#define CHAR2INT(x) (x == 0 ? 0 : x - '0') // convert a char into his int value
#define INT2CHAR(x) (x + '0') // convert an int into his ascii value
#define IS_NUM(x) (x >= '0' && x <= '9') //cehck is a char is beteween 0 and 9
#define IS_CAPS(x) (x >= 'A' && x <= 'Z') // wheck if a char is capital letters
//Prototypes
void *g_malloc (size_t size); //things not used anymore but still cool
int my_getnbr (char const *str); // get a number from a string
int my_putnbr (int nb); // put a int on the standard output
int my_strcmp (char const *str1, char const *str2); // compare two string return 0 if equals
char **my_str_to_word_array (const char *str); // convert a string ito an array of words
char *get_next_line (const int fd); // get a line from th sandard output
int my_strlen (const char *str); // return the size of a null terminated string
int my_putchar (const int c); // put a char into the standard output
int my_putstr (const char *str); // print a string
void my_put_2d_char (const char **array); // print a char ** with '\n' at the end
char *my_strcpy (const char *str); // cp a string and return it's pointer
int is_str_num (const char *str); // check if a string is a number
int my_strfind (char const *str, char const *to_find); // find a word in a string
int print_int (va_list args); // linker for printf
int print_string (va_list args); // linker for printf
int print_char (va_list args); // linker for printf
int print_percent (va_list args); // linker for printf
int my_printf (char *, ...); // simple printf like options : %d %i %s %c
int my_random (void); // gegerate random number using /dev/urandom
#endif

/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef _BSQ_H_
#define _BSQ_H_
#define IS_NUM(x) (x <= '9' && x >= '0')
#define CHAR2INT(x) (x == '0' ? 0 : x - '0')

typedef struct file_s {
	char *buffer;
	struct stat info;
	int fd;
} *file_t;

typedef struct bsq_size_s {
	long int width;
	long int height;
	long int start_of_map;
} bsq_size_t;

file_t ini_file (char *path);
void free_file (file_t file);
int get_width (file_t file, int start_offset);
int get_height (file_t file);
bsq_size_t get_size (file_t file);
void cat_buffer(file_t file, bsq_size_t size);
int **convert_to_int_array (bsq_size_t size, file_t map);
char **char_star_to_char_star_star (char *str, bsq_size_t size);
void free_char_star_star (char **star);
int my_putchar (int c);
int my_strlen (const char*);
int my_putstr (const char*);
void print_bsq (char **star);
char **convert_bsq (char **star);
int **get_greater_square (int **int_bsq, bsq_size_t size);
int compare_value (int x, int y, int z);
int **convert_charss_intss (char **star, bsq_size_t size);
void free_int_star_star (int **int_bsq, bsq_size_t size);
int *get_coord_square (int **int_bsq, bsq_size_t size);
char **result_bsq (char **star, int *coord);
void free_ressources (int *, int**, char**, bsq_size_t);
int special_case (bsq_size_t, file_t);
int columns_special (char **, int i);
int line_special (char **star);
#endif

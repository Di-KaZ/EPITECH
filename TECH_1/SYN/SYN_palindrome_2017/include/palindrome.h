/*
** EPITECH PROJECT, 2018
** header of palindrome
** File description:
** palindrome
*/

#ifndef _PALINDROME_
#define _PALINDROME_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

enum flags {
	n_flag = 1,
	p_flag = 2,
	b_flag = 4,
	imin_flag = 8,
	imax_flag = 16,
	h_flag = 32
};

typedef struct palindrome_s {
	char *b_conv_start;
	char *to_find;
	char *start;
	char *rev;
	int base;
	unsigned int flags;
	int imin;
	int imax;
} palindrome_t;

void flag_h(__attribute__((unused))char *arg,
		__attribute__((unused))palindrome_t *);
void flag_n(char *arg, palindrome_t *);
void flag_p(char *arg, palindrome_t *);
void flag_b(char *arg, palindrome_t *);
void flag_imin(char *arg, palindrome_t *);
void flag_imax(char *arg, palindrome_t *);
int is_str_num(char *str);
int algorithm(palindrome_t *);
void algorithm_using_p(palindrome_t *);
void algorithm_solo(palindrome_t *);
char *my_revstr(char *);
char *add_n_transform(char *, char *, char *);
int active_imin_flag(palindrome_t *p, int iteration);
int active_imax_flag(palindrome_t *p, int iteration);
char *convert_in_base(int nb, int base);
int revert_in_decimal(char *nb, int base);
int is_overflowing(char *);

#endif


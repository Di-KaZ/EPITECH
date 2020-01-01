/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <stdlib.h>
#include "struct.h"
/* Macros */
#define CHAR2INT(x) (x == 0 ? 0 : w - '0')
/*Prototypes of all Functions*/
elem_t *rotate_left  (elem_t*);
elem_t *rotate_right (elem_t*);
elem_t *swap	     (elem_t*);
elem_t *push         (elem_t**,elem_t*);
void free_list       (elem_t *list);
int  my_get_nbr      (const char*);
int  my_strlen       (const char*);
int  my_putstr       (const char*);
int  my_putchar      (int);
int  my_put_nbr      (int);
int is_sorted        (elem_t*);
void pushswap        (elem_t*,elem_t*);
void sc              (elem_t**,elem_t**);
void sa              (elem_t**,int);
void sb              (elem_t**);

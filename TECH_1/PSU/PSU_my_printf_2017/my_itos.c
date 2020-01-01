/*
** EPITECH PROJECT, 2017
** my_itos
** File description:
** .
*/

#include "my.h"
#include <stdlib.h>

char *my_itos (int nb) {
    int bit = 1;
    int len = 0;
    char *istr;
    int isneg = 0;

    if(nb < 0) {
	nb *= -1;
	isneg = 1;
    }
    for(;bit < nb; len += 1)
	bit *= 10;
    bit /= 10;
    istr = malloc(sizeof(*istr) * (len + 2));
    for(int i = 0; i <= len; i += 1) {
	if(isneg == 1) {
	    i = 1;
	    istr[0] = '-';
	    isneg = 0;
	}
	if(bit <= 0)
	    break;
	istr[i] = INT2CHAR(nb / bit % 10);
	bit /= 10;
    }
    istr[len + 1] = '\0';
    return(istr);
}


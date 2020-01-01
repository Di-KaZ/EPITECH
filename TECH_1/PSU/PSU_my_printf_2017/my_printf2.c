#include <stdarg.h>
#include "my.h"

char *my_ctos(int c)
{
    char str[2] = {c, '\0'};
    char *ptrstr = str;
    return(ptrstr);
}
char *converter (void *toconv, char opt)
{
    switch(opt) {
    case 'd':
	return(my_itos(*(int *)toconv));
    case 's':
	return((char *)toconv);
    case 'c':
	return(my_ctos(*(int*)toconv));
    default:
	return('\0');
    }
}

char which_opt (char *str, char **endstr)
{
    if (*str == '%' && *(str - 1) != '%')
	return(*(str + 1));
    return('\0');
}

int nbr_arg (char *str)
{
    int nbr_ar = 0;

    while(*str != '\0') {
	if(which_opt(str, &str) != '\0')
	    nbr_ar += 1;
	    str += 1;
    }
    return(nbr_ar);
}

int my_printf(char *str, ...)
{
    va_list args;
    int len = nbr_arg(str);
    char opt = '\0';
    int nb_printchar = 0;
    int i = 0;

    va_start(args, len);
    while(*str != '\0') {
    opt = which_opt(str,&str);
    if(opt != '\0') {
	nb_printchar += my_putstr(converter(va_arg(args,void*),opt));
	str += 1;
    }
    else {
	my_putchar(str[i]);
	nb_printchar += 1;
    }
    str += 1;
    }
    va_end(args);
    printf("%d\n",nb_printchar);
    return(nb_printchar);
}

/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** tools
*/


#include "server.h"

char *clean_str(char *str)
{
    for (int i = 0; str[i]; i += 1) {
        if (str[i] == '\n' || str[i] == '\r')
            str[i] = '\0';
    }
    return (str);
}

int is_alpha(const char *str)
{
    if (*str == '\0')
        return (1);
    if (*str >= '0' && *str <= '9')
        return (is_alpha(str + 1));
    return (0);
}
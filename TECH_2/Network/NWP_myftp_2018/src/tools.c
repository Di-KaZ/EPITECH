/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** tools
*/

#include "ftp.h"

int my_strlen(const char *str)
{
    int len;

    while (str[len++]);
    return (len);
}

char *get_currentdir(void)
{
    char buf[1024];

    if (getcwd(buf, 1024) == NULL)
        return (NULL);
    return (strdup(buf));
}

void clean_str(char *str)
{
    for (int i = 0; str[i]; i += 1) {
        if (str[i] == '\n' || str[i] == '\r')
            str[i] = '\0';
    }
}

int quit_error(int exit_code, const char *msg)
{
    dprintf(2, "%s", msg);
    return (exit_code);
}

int is_alpha(const char *str)
{
    if (*str == '\0')
        return (1);
    if (*str >= '0' && *str <= '9')
        return (is_alpha(str + 1));
    return (0);
}
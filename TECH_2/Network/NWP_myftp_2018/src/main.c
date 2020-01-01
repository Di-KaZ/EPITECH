/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** new_ftp
*/

#include "ftp.h"

int print_usage(int exit_code, const char *bin_name)
{
    printf("USAGE:\n"
                "%s\t[port] [home directory]\n"
                "\tport -> integer\n"
                "\thome directory -> path\n", bin_name);
    return (exit_code);
}

int main (__attribute((unused))int ac, const char **av)
{
    return (run(av));
}
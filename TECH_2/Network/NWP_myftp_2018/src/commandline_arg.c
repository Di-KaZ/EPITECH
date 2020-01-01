/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** commandline_arg
*/

#include "ftp.h"

int count_file_line(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    int line_num = 0;
    size_t size = 0;

    if (!file)
        return (-1);
    while (getline(&line, &size, file) != - 1) {
        line_num += 1;
    }
    fclose(file);
    return (line_num);
}

char **create_map(const char *filepath)
{
    int i = 0;
    int map_size = count_file_line(filepath);
    char **map = NULL;
    char *line = NULL;
    FILE *file = fopen(filepath, "r");

    if (map_size == -1)
        return (NULL);
    map = malloc(sizeof(char *) * (map_size + 1));
    while (getline(&line, (size_t)0, file) != - 1)
        map[i++] = line;
    map[i] = NULL;
    fclose(file);
    return (map);
}

void get_port(server_t *param, const char **arg)
{
    if (strcmp(arg[0], "-p") == 0 && strlen(arg[1]) == 4 && is_alpha(arg[1])) {
       param->s_port = atoi(arg[1]);
    }
}

void get_gravity(server_t *param, const char **arg)
{
    if (strcmp(arg[0], "-g") == 0 && is_alpha(arg[1])) {
        param->gravity = atoi(arg[1]);
    }
}

void get_map(server_t *param, const char **arg)
{
    if (strcmp(*arg, "-m") == 0) {
        param->map = create_map(arg[1]);
    }
}
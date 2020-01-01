/*
** EPITECH PROJECT, 2019
** server
** File description:
** commandline_arg
*/

#include "server.h"

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

int is_map_line_valid(const char *line, int line_num)
{
    if (strlen(line) == 0) {
        PRINT_ERROR_MSG_N_RETUN(ERR_BAD_MAP, 0);
    }
    for (int i = 0; line[i]; i += 1) {
        if (line[i] != '_' && line[i] != 'e' && line[i] != 'c') {
            dprintf(2, "\x1b[31m[ERROR]\x1b[0m\tline n° %d \"%s\"\n",
                                            line_num + 1, line);
            PRINT_INFO_MSG(INFO_MAP_CHAR1);
            PRINT_INFO_MSG(INFO_MAP_CHAR2);
            PRINT_ERROR_MSG_N_RETUN(ERR_BAD_MAP, 0);
        }
    }
    return (1);
}

static char  **close_n_print(FILE *file, server_t *param,
                                char **map, int map_size)
{
    map[map_size] = NULL;
    fclose(file);
    param->max_x = strlen(map[0]);
    param->max_y = map_size;
    PRINT_INFO_MSG(INFO_MAP_GOOD);
    return (map);
}

char **create_map(const char *filepath, server_t *param)
{
    int map_size = count_file_line(filepath);
    char **map = NULL;
    char *line = NULL;
    FILE *file = fopen(filepath, "r");
    size_t size = 0;

    if (map_size == -1) {
        PRINT_INFO_MSG(INFO_WRONG_MAP);
        return (NULL);
    }
    map = malloc(sizeof(char *) * (map_size + 1));
    for (int i = 0; getline(&line, &size, file) != - 1; i += 1) {
        clean_str(line);
        if (is_map_line_valid(line, i))
            map[i] = line;
        else
            return (NULL);
        line = NULL;
    }
    return (close_n_print(file, param, map, map_size));
}

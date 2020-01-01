/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "client.h"

void send_to_serv(client_parameters_t *client, char *message)
{
    char *to_send;
    to_send = strdup(message);
    send(client->sd, message, strlen(message), 0);
}

char **str_to_wordtab(char *str, int width, int height)
{
    char **tab = malloc(sizeof(char *) * (height + 1));
    int k = 0;

    for (int y = 0; y < height; y += 1) {
        tab[y] = malloc(sizeof(char) * (width + 1));
        memcpy(tab[y], str + k, width);
        tab[y][width] = '\0';
        k += width;
    }
    tab[height] = NULL;
    return (tab);
}

int get_command(client_parameters_t *client, char **buffer)
{
    FILE *to_read = fdopen(client->sd, "r");
    size_t len = 0;
    int size = 0;

    size = getline(buffer, &len, to_read);
    return (size);
}

int help(const char *str)
{
    printf("USAGE :\n");
    printf("\t%s -h <ip> -p <port>\n", str);
    return (84);
}
/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** update_info_thread
*/
#include "client.h"

static const int screen_multiplier_g = 50;

static int do_nothing(__attribute__((unused))update_thread_t *nothing,
__attribute__((unused))char *line)
{
    return (0);
}

static int update_player_pos(update_thread_t *update, char *line)
{
    line = line + 7;
    int id = atoi(line);
    sfVector2f pos = {0, 0};
    int score = 0;

    while (*line && *line++ != ' ');
    pos.x = atof(line) * screen_multiplier_g;
    while (*line && *line++ != ' ');
    pos.y = atof(line) * screen_multiplier_g;
    while (*line && *line++ != ' ');
    score = atoi(line);
    if (id == update->graphic->player1->id) {
        update->graphic->player1->set_position(update->graphic->player1, pos);
        update->graphic->player1->position = pos;
        update->graphic->player1->score = score;
        sfRenderWindow_setView(update->graphic->win, update->graphic->view);
    } else {
        update->graphic->player2->set_position(update->graphic->player2, pos);
        update->graphic->player2->position = pos;
        update->graphic->player2->score = score;
    }
    return (0);
}

static int finish_func(update_thread_t *update, char *line)
{
    int id_win = 0;

    line = line + 7;
    id_win = atoi(line);
    if (id_win == update->graphic->player1->id) {
        printf("You Win !\n");
    } else if (id_win != update->graphic->player1->id && id_win != -1){
        printf("You Lose ! Better luck next time :)\n");
    }
    if (id_win == -1) {
        if (update->graphic->player1->score > update->graphic->player2->score)
            printf("You Win !\n");
        else if (update->graphic->player1->score <
            update->graphic->player2->score)
            printf("You Lose ! Better luck next time :)\n");
        else if (update->graphic->player1->score ==
            update->graphic->player2->score)
            printf("No match ! Try again\n");
    }
    sfRenderWindow_close(update->graphic->win);
    return (0);
}

static const update_game_fnc_ptr_t update_function_g[] =
{
    {"PLAYER", &update_player_pos},
    {"COIN", &command_coin},
    {"FINISH", &finish_func},
    {NULL, &do_nothing}
};

int execute_recived_order(update_thread_t *update, char *line)
{
    int return_val = 0;

    for (int i = 0; update_function_g[i].command; i += 1) {
        if (strstr(line, update_function_g[i].command)) {
            return_val = update_function_g[i].func_ptr(update, line);
            if (return_val != 0)
                return (return_val);
        }
    }
    return (0);
}

int get_line_with_read(int fd, char buffer[], int max_size)
{
    char c = '\0';
    int i = 0;

    while (c != '\n' && i < max_size) {
        if (read(fd, &c, 1) == 0)
            return (0);
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    return (i);
}

void *update_info_cli_thread(void *arg)
{
    update_thread_t *update = (update_thread_t *)arg;
    char line[1024] = {0};
    int return_val = 0;

    FD_SET(update->client->sd, &update->graphic->readfds);
    memset(&line, 0, 1024);
    while (1) {
        if (select(update->client->sd + 1,
            &update->graphic->readfds, NULL, NULL, NULL) < 0)
            return (NULL);
        if (FD_ISSET(update->client->sd, &update->graphic->readfds)) {
            get_line_with_read(update->client->sd, line, 1024);
            return_val = execute_recived_order(update, line);
            memset(&line, 0, 1024);
            if (return_val != 0)
                return (NULL);
        }
    }
    return (0);
}
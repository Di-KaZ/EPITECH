/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** main_plus
*/

#include "client.h"


void start_graphical_n_thread(update_thread_t *update, pthread_t *thread,
                                            graphic_display_t *graphic)
{
    update->graphic = graphic;
    update->graphic->run(update->graphic->this);
    pthread_cancel(*thread);
    pthread_join(*thread, NULL);
}
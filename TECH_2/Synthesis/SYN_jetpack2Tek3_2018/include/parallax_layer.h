/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** parallax_layer
*/
#include<SFML/Graphics.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <tools.h>
#include "assets_manager.h"

#pragma once

typedef struct parallax_layer_s {
    void (*move)(struct parallax_layer_s *, float speed, float reset_pos);
    void (*display)(struct parallax_layer_s *, sfRenderWindow *);
    sfSprite *first;
    sfSprite *second;
    sfSprite *temp;
} parallax_layer_t;

parallax_layer_t *initialize_parallax_layer(sfTexture *);
void move_parallax_layer(struct parallax_layer_s *this,
                        float speed, float reset_pos);
void display_parallax_layer(struct parallax_layer_s *this, sfRenderWindow *win);

typedef struct space_parallax_s {
    void (*move)(struct space_parallax_s *, float);
    void (*display)(struct space_parallax_s *, sfRenderWindow *);
    parallax_layer_t *one;
    parallax_layer_t *two;
    parallax_layer_t *three;
    parallax_layer_t *four;
    parallax_layer_t *five;
} space_parallax_t;

space_parallax_t *initialize_space_parallax(assets_manager_t *manager);
void move_space_parallax(struct space_parallax_s *spaaace, float reset_pos);
void display_space_parallax(struct space_parallax_s
                            *spaace, sfRenderWindow *win);

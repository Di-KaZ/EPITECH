/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** animator
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
#include <SFML/System/Time.h>

#pragma once

typedef struct animator_s {
    sfIntRect (*update_frame)(struct animator_s *, sfSprite *);
    sfTexture *text_sheet;
    sfClock *framerate_c;
    float framerate;
    float frame_offset;
    float current_offset;
    float max_offset;
} animator_t;

animator_t *initialize_animator(sfTexture *text,
        float frame_offeset, float framerate);
sfIntRect update_frame(struct animator_s *, sfSprite *);
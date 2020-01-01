/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** assets_manager
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

#pragma once


typedef struct node_font_s {
    char *name;
    sfFont *font;
    struct node_font_s *next;
} node_font_t;

typedef struct node_texture_s {
    char *name;
    sfTexture *texture;
    struct node_texture_s *next;
} node_texture_t;

node_texture_t *create_new_node_text(const char *);

typedef struct assets_manager_s {
    sfTexture *(*get_texture)(struct assets_manager_s *, const char *);
    int (*load_texture)(struct assets_manager_s *, const char *);
    sfFont *(*get_font)(struct assets_manager_s *, const char *);
    int (*load_font)(struct assets_manager_s *, const char *);
    void (*destroy)(struct assets_manager_s *);
    node_texture_t *t_head;
    node_font_t *f_head;
    struct assets_manager_s *this;
} assets_manager_t;

assets_manager_t *initialize_assets_manager(void);
sfTexture *assets_manager_get_texture(struct assets_manager_s *, const char *);
int assets_manager_load_texture(struct assets_manager_s *, const char *);
sfFont *assets_manager_get_font(struct assets_manager_s *, const char *);
int assets_manager_load_font(struct assets_manager_s *, const char *);
void destroy_assets_manager(struct assets_manager_s *);

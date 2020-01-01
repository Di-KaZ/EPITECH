/*
** EPITECH PROJECT, 2019
** jetpack2Tek3
** File description:
** client_connection
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <pthread.h>
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
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "assets_manager.h"
#include "parallax_layer.h"
#include "animator.h"

#pragma once

typedef struct map_parameters_s {
    char **map;
    int width;
    int height;
} map_parameters_t;

typedef struct game_parameters_s {
    int id;
    struct map_parameters_s *map;
} game_parameters_t;

typedef struct client_parameters_s {
    char *ip;
    char *port;
    struct sockaddr_in socketServ;
    struct sockaddr_in client;
    int sd;
} client_parameters_t;
    /*  PROTOTYPES   */


typedef struct update_thread_s {
    client_parameters_t *client;
    game_parameters_t *game;
    struct graphic_display_s *graphic;
} update_thread_t;

typedef struct update_game_fnc_ptr_s {
    char *command;
    int(*func_ptr)(update_thread_t *, char *);
} update_game_fnc_ptr_t;

char **str_to_wordtab(char *str, int width, int height);
int get_serv_id(client_parameters_t *client);
map_parameters_t *get_serv_map(client_parameters_t *client);
int get_command(client_parameters_t *client, char **buffer);
void send_to_serv(client_parameters_t *client, char *message);
int initialize_client_param(client_parameters_t *client, int ac,
const char **av);
int check_host(char *ip, const char *port);
int help(const char *str);
int socket_and_connect(client_parameters_t *client);
void *update_info_cli_thread(void *arg);
int command_coin(update_thread_t *update, char *line);

////////////////////////////////////////////////////
typedef struct title_s {
    void (*destroy)(struct title_s *);
    sfSprite *spr;
    sfVector2f position;
    struct title_s *this;
} title_t;

title_t *initialize_title(sfVector2f pos, sfTexture *);
void destroy_title(struct title_s *this);

////////////////////////////////////////////////////
typedef struct map_s {
    void (*draw)(struct map_s *, sfRenderWindow *);
    void (*destroy)(struct map_s *);
    int max_x;
    int max_y;
    title_t ***title_map;
    struct map_s *this;
    animator_t *coin_anim;
} map_t;
map_t *initialize_map(int x, int y, const char **map, assets_manager_t *);
void draw_map(map_t *this, sfRenderWindow *win);
void destroy_map(map_t *this);

////////////////////////////////////////////////////
typedef struct player_s {
    void (*set_position)(struct player_s *, sfVector2f);
    void (*draw)(struct player_s *, sfRenderWindow *);
    void (*drestroy)(struct player_s *);
    sfSprite *spr;
    sfVector2f position;
    int score;
    int id;
    struct player_s *this;
    sfText *score_txt;
} player_t;
player_t *initialize_player(int id, sfVector2f pos, sfTexture *, sfFont *);
void set_player_position(struct player_s *this, sfVector2f pos);
void draw_player(struct player_s *this, sfRenderWindow *win);
void destroy_player(struct player_s *this);

////////////////////////////////////////////////////
typedef struct graphic_display_s {
    int (*run)(struct graphic_display_s *);
    void (*destroy)(struct graphic_display_s *);
    sfRenderWindow *win;
    map_t *map;
    player_t *player1;
    player_t *player2;
    struct graphic_display_s *this;
    sfEvent event;
    struct client_parameters_s *client;
    fd_set readfds;
    sfMutex *lock;
    assets_manager_t *ass_manager;
    sfView *view;
    space_parallax_t *space;
} graphic_display_t;

graphic_display_t *initialize_graphical(int y, int x, int id, const char **map);
int run_graphical(struct graphic_display_s *this);
void destroy_graphic(struct graphic_display_s *this);
/////////////////////
void start_graphical_n_thread(update_thread_t *update, pthread_t *thread,
                                            graphic_display_t *graphic);
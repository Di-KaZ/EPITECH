/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** ftp
*/

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

//STRUCT

typedef struct player_s {
    int fd;
    float x;
    float y;
    int jetpack_status;
    int is_ready;
    int score;
} player_t;

typedef struct server_s {
    int s_port;
    int s_socket_fd;
    char **map;
    int gravity;
    int max_x;
    int max_y;
    struct sockaddr_in serv_conf;
    struct sockaddr_in cli_conf;
    player_t players[2];
    fd_set readfds;
    size_t cli_socket_size;
    int last_fd;
    int new_client_fd;
    int game_started;
    struct timeval timeout;
} server_t;

typedef struct  command_pair_s {
    char *prompt;
    int (*handle_cmd_ptr)(player_t *client,
        const char *line, fd_set *readfds, char **map);
} command_pair_t;

//PROTOTYPE
int game_algorithm(server_t *server);
int map_cmd(player_t *client, const char *line, fd_set *readfds, char **map);
int fire_cmd(player_t *client, const char *line, fd_set *readfds, char **map);
int ready_cmd(player_t *client, const char *line, fd_set *readfds, char **map);
int id_cmd(player_t *client, const char *line, fd_set *readfds, char **map);
int quit_cmd(player_t *client, const char *line, fd_set *reads, char **map);
int none_cmd(player_t *client, const char *line, fd_set *reads, char **map);
int run(const char **av);
void get_greater_fd(server_t *server);
int initialize_socket(server_t *server);
int initialize_server(server_t *server, const char **av);
int my_strlen(const char *str);
char *get_currentdir(void);
int accept_new_client(server_t *server);
int exec_recived_command(server_t *server);
char *clean_str(char *str);
int quit_error(int exit_code, const char *msg);
int is_alpha(const char *str);
void log_client_in_user(player_t *client);
int passwd_cmd(player_t *client, const char *line, fd_set *readfds, char **map);
int user_cmd(player_t *client, const char *line, fd_set *readfds, char **map);
int count_file_line(const char *filepath);
char **create_map(const char *filepath, server_t *param);
void get_port(server_t *param, const char **arg);
void get_gravity(server_t *param, const char **arg);
void get_map(server_t *param, const char **arg);
int check_collision(server_t *server);
void close_server(server_t *server);
void register_new_clients(server_t *server);
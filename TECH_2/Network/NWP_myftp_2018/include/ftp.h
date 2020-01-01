/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** ftp
*/

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
#include<fcntl.h>
#include <sys/time.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

//STRUCT

typedef struct player_s {
    int fd;
    float x;
    float y;
    int jetpack_status;
} player_t;

typedef struct server_s {
    int s_port;
    int s_socket_fd;
    char **map;
    int gravity;
    struct sockaddr_in serv_conf;
    struct sockaddr_in cli_conf;
    player_t players[2];
    fd_set readfds;
    size_t cli_socket_size;
    int last_fd;
    int new_client_fd;
} server_t;

typedef struct  command_pair_s {
    char *prompt;
    int (*handle_cmd_ptr)(player_t *client, const char *line, fd_set *readfds);
} command_pair_t;

//PROTOTYPE

int quit_cmd(player_t *client, const char *line, fd_set *reads);
int none_cmd(player_t *client, const char *line, fd_set *reads);
int run(const char **av);
void get_greater_fd(server_t *server);
int initialize_socket(server_t *server);
int initialize_server(server_t *server, const char **av);
int my_strlen(const char *str);
char *get_currentdir(void);
int accept_new_client(server_t *server);
int exec_recived_command(server_t *server);
void clean_str(char *str);
int quit_error(int exit_code, const char *msg);
int is_alpha(const char *str);
void log_client_in_user(player_t *client);
int passwd_cmd(player_t *client, const char *line, fd_set *readfds);
int user_cmd(player_t *client, const char *line, fd_set *readfds);
int count_file_line(const char *filepath);
char **create_map(const char *filepath);
void get_port(server_t *param, const char **arg);
void get_gravity(server_t *param, const char **arg);
void get_map(server_t *param, const char **arg);

// INFO MESSAGES

#define INFO_CON_CLI "Connection from : %s:%d.\n"
#define INFO_LOGIN_CLI "client fd : %d logged as %s\n"
#define INFO_USRNAME_CLI "client fd : %d username : %s\n"
#define INFO_PSSWD_CLI "client fd : %d password : %s\n"
// ERROR MESSAGES

#define ERR_SELECT "Unable to bind select.\n"
#define ERR_ACCEPT "Unable to accept client request.\n"
#define ERR_EXEC_CMD "Unable to execute requested command.\n"
#define ERR_BIND "Unable to bind socket.\n"
#define ERR_SOCK "Unable to create socket.\n"
#define ERR_LISTEN "Unable to listen.\n"
#define HELP "./serverJ2T3 -p <port> -g <gravity> -m <map>"
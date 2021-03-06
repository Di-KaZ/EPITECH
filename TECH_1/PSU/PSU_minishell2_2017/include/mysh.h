/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef _MYSH_
#define _MYSH_
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include "my_lib_c.h"
typedef void (*t_handler(int));

typedef struct env_s {
	char *path;
	struct env_s *next;
} env_t;

void disp_prompt (int, char **);
char **my_str_to_word_array (char const *str);
void disp_env (env_t *env);
void exec_prog (char **line, char**env);
void free_line (char **line, char *to_free);
void cd_command (char **line, env_t *env);
char *search_path(env_t *env, const char *to_find);
char *add_str (const char *str1, const char *str2);
void exec_binary (char **line, env_t *env);
int ok_checker (const char *path);
void manage_signal (int sig);
env_t *ini_env (char **env);
void setenv_bi (char **line, env_t *list);
void unsetenv_bi (char **line, env_t *list);
int aleready_exist (char *, char *);
void free_evn (env_t *env);
void disp_env_l (char **line, env_t *env);
void exit_l (char **line, env_t *env);
void clear_l (char **line, env_t *env);
void free_env (env_t *);
char **chained_to_array (env_t *env);
char **path_parser (const char *path);
int str_first_find (char *str1, char *to_find);
#endif

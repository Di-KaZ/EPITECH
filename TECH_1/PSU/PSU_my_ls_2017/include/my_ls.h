/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/
#define NO_FLAG(x) (x->l_flag == 0 && x->rr_flag == 0 && x->d_flag == 0 && x->r_flag == 0 && x->t_flag == 0)
/* Includes */
#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
/* Functions prototypes */
option_t *init_flag      (void);
int fill_flag            (option_t**, const char*);
option_t *is_option      (int ac, char **av);
char *directory_name     (int ac, char **av);
int manage_dir           (int ac, char **av, option_t*);
int my_putchar           (int);
int my_putstr            (const char*);
int my_strlen            (const char*);
void get_info_files      (info_file_t **, files_t*);
void printer             (info_file_t*, option_t*, char *dir_name);
void free_info_files     (info_file_t**);
void d_flag              (char*,option_t*);
void no_flag             (info_file_t*);
void rr_flag             (char*, info_file_t*,option_t*);
int  manage_dir_rec      (char*, info_file_t**);
char *add_dir_name	 (char*, char*);
void print_auth          (char *path);
void print_auth2         (struct stat*);
void disp_month          (struct stat*);
void l_flag              (info_file_t*);

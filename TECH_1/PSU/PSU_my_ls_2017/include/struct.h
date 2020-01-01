/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

/* Sturct that save all the flags found */
typedef struct option_s {
	int l_flag;
	int rr_flag;
	int d_flag;
	int r_flag;
	int t_flag;
} option_t;

typedef struct info_file_s {
	struct dirent *info;
	struct info_file_s *next;
} info_file_t;

typedef struct dirent files_t;

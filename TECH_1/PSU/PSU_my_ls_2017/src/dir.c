/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_ls.h"

char *directory_name(int ac,char ** av)
{
	if(!av[1])
		return(".");
	for (int i = 1; i < ac; i += 1)
		if (av[i][0] != '-')
			return(av[i]);
	return(".");
}

int manage_dir (int ac, char **av, option_t *options)
{
	char *dir_name = directory_name(ac, av);
	DIR *dir = opendir(dir_name);
	files_t *current_file = NULL;
	info_file_t *list = NULL;

	if (dir == NULL)
		return (84);
	current_file = readdir(dir);
	while (current_file != NULL) {
		get_info_files (&list, current_file);
		current_file = readdir(dir);
	}
	printer(list, options, dir_name);
	free_info_files(&list);
	closedir(dir);
	return (0);
}

int manage_dir_rec (char *dir_name, info_file_t **list)
{
	files_t *current_file = NULL;
	DIR *dir = opendir(dir_name);

	current_file = readdir(dir);
	while (current_file != NULL) {
		get_info_files(list, current_file);
		current_file = readdir(dir);
	}
	return (0);
}

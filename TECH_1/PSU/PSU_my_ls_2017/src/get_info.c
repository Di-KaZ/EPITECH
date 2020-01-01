/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_ls.h"

void get_info_files (info_file_t **file, files_t *info)
{
	info_file_t *temp = *file;
	info_file_t *to_add = malloc(sizeof(*to_add));
	to_add->info = info;
	to_add->next = NULL;

	if (!*file) {
		free(to_add);
		*file = malloc(sizeof(*to_add));
		(*file)->info = info;
		(*file)->next = NULL;
	}
	else {
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = to_add;
	}
}

void free_info_files (info_file_t **file)
{
	info_file_t *temp = NULL;

	while ((*file)->next != NULL) {
		temp = *file;
		*file = (*file)->next;
		free(temp);
	}
	free(*file);
}

/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "my_ls.h"

void printer (info_file_t *list, option_t *options, char *dir_name)
{
	d_flag (dir_name, options);
	if (NO_FLAG(options))
		no_flag(list);
	rr_flag(dir_name, list, options);
	if (options->l_flag == 1 && options->d_flag == 0)
		l_flag(list);
}

void no_flag (info_file_t *list)
{
	int isprev = 0;

	while (list->next != NULL) {
		if (*(list->info->d_name) != '.') {
			if (isprev == 1)
				my_putstr("  ");
			my_putstr(list->info->d_name);
			isprev = 1;
		}
		list = list->next;
	}
}

void d_flag (char *dir_name, option_t *options)
{
	if (options->l_flag == 1 && options->d_flag == 1) {
		print_auth(dir_name);
		my_putchar(' ');
	}
	if (options->d_flag == 1) {
		my_putstr(dir_name);
		return;
	}
}

void rr_flag (char *dir_name, info_file_t *list, option_t *options)
{
	info_file_t *scan_for_dir = list;
	info_file_t *next_dir = NULL;
	char *next_dir_name = NULL;

	if (options->rr_flag == 1) {
		my_printf("%s:\n",dir_name);
		if (options->l_flag == 1)
			l_flag(list);
		else
			no_flag(list);
		my_putstr("\n\n");
		while (scan_for_dir != NULL) {
			while (scan_for_dir->info->d_type != DT_DIR ||
			*(scan_for_dir->info->d_name) == '.')
				scan_for_dir = scan_for_dir->next;
		  next_dir_name = add_dir_name(dir_name,
					scan_for_dir->info->d_name);
			my_printf("%s:\n",next_dir_name);
			manage_dir_rec(next_dir_name, &next_dir);
			free(next_dir_name);
			if (options->l_flag == 1)
				l_flag(list);
			else
				no_flag(next_dir);
			free_info_files(&next_dir);
			next_dir = NULL;
			next_dir_name = NULL;
			if ((scan_for_dir = scan_for_dir->next) != NULL)
				my_putstr("\n\n");
		}
	}
}

void l_flag(info_file_t *list)
{
	while (list->next != NULL) {
		if ((*list->info->d_name) != '.') {
			print_auth(list->info->d_name);
			my_printf(" %s", list->info->d_name);
		}
		list = list->next;
		if (list->next != NULL && (*list->info->d_name) != '.')
			my_putchar('\n');
	}
}

/*
** EPITECH PROJECT, 2018
** main
** File description:
** main fuction of minishell
*/

#include "mysh.h"

char *command_char[8] =
{
	"",
	"env",
	"exit",
	"cd",
	"clear",
	"setenv",
	"unsetenv",
	NULL,
};

void (*command_ptr[7])(char **, env_t *) =
{
	nothing,
	disp_env_l,
	exit_l,
	cd_command,
	clear_l,
	setenv_bi,
	unsetenv_bi
};

void free_env (env_t *env)
{
	env_t *temp = env;
	while (env) {
		env = env->next;
		free(temp);
		temp = env;
	}
}

void free_line (char **line, char *to_free)
{
	int i = 0;

	for (i = 0; line[i] != NULL; i += 1) {
		free(line[i]);
		line[i] = NULL;
	}
	free(line[i]);
	free(line);
	if (to_free)
		free(to_free);
	to_free = NULL;
	line = NULL;
}

void manage_command (char **line, env_t *env)
{
	for (int i = 0; command_char[i]; i += 1) {
		if (my_strcmp(command_char[i], line[0]) == 0) {
			command_ptr[i](line, env);
			return;
		}
	}
	exec_binary (line, env);
}

int main (int ac, char **av, char **env)
{
	env_t *list = ini_env(env);
	char **line = NULL;
	char *to_free = NULL;

	while (1) {
		signal(SIGINT, manage_signal);
		disp_prompt(ac, av);
		to_free = format_string(get_next_line(0));
		line = my_str_to_word_array(to_free);
		if (!to_free) {
			my_putstr(" exit");
			free_env(list);
			return (0);
		}
		manage_command (line, list);
		free_line(line, to_free);
	}
	free_env(list);
	return (0);
}

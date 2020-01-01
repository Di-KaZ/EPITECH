#include "mysh.h"

env_t *add_path (env_t *list, char *path)
{
	env_t *to_add = malloc(sizeof(env_t));
	env_t *temp = list;

	to_add->path = my_strcpy(path);
	to_add->next = NULL;
	if (!list) {
		return (to_add);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = to_add;
	return (list);
}

env_t *ini_env (char **envchar)
{
	env_t *env_list = NULL;
	int i;

	for (i = 0; envchar[i]; i += 1)
		env_list = add_path(env_list, envchar[i]);
	if (i == 0) {
		if (!(env_list = malloc(sizeof(env_t))))
		    return (NULL);
		env_list->path = NULL;
		env_list->next = NULL;
	}
	return (env_list);
}

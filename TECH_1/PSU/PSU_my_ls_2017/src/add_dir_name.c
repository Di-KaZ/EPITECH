#include "my_ls.h"

char *add_dir_name (char *str1, char *str2)
{
	int j;
	int len = my_strlen(str1) + my_strlen(str2);
	char *added_string = malloc(sizeof(added_string) * (len + 2));

	for (j = 0; str1[j] != '\0'; j += 1) {
		added_string[j] = str1[j];
	}
	added_string[j] = '/';
	j += 1;
	for (int i = 0; str2[i] != '\0'; j += 1) {
		added_string[j] = str2[i];
		i += 1;
	}
	added_string[j] = '\0';
	return (added_string);
}

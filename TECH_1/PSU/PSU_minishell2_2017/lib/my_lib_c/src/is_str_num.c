#include "my_lib_c.h"

int is_str_num (const char *str)
{
	for (int i = 0; str[i]; i += 1)
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

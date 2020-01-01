/*
 ** EPITECH PROJECT, 2017
 ** my_strncmp
 ** File description:
 ** compare a string till n
 */

int my_strncmp(char const *s1, char const *s2, int n) {
	int i = 0;
	while(s1[i] != '\0' && i <= n)
		if(s2[i] == '\0') {
			return(1);
			if(s1[i] < s2[i])
				return(-1);
			if(s1[i] > s2[i])
				return(1);
			i += 1;
		}
	if(s2[i] != '\0' && i <= n)
		return(-1);
	return(0);
}


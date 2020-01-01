/*
 ** EPITECH PROJECT, 2017
 ** my_strcmp
 ** File description:
 ** compare two string
 */

int my_strcmp(char const *s1, char const *s2) {
	int i = 0;
	while(s1[i] != '\0') {
		if(s2[i] == '\0')
			return(1);
		if(s1[i] < s2[i])
			return(-1);
		if(s1[i] > s2[i])
			return(1);
		i += 1;
	}
	if(s2[i] != '\0')
		return(-1);
	return(0);
}


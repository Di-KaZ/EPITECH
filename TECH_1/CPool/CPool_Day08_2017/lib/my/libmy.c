#include<unistd.h>
void my_putchar(char c) {
	write(1, &c, 1);
}

int my_isneg(int n) {
	if (n < 0) {
		my_putchar('N');
	}
	else {
		my_putchar('P');
	}
	return (0);
}

int my_put_nbr(int nb) {
	int last_nb;
	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	}
	else if (nb >= 10) {
		last_nb = nb % 10;
		my_putchar(last_nb + 48);
		nb = (nb - last_nb) / 10;
	}
	else {
		my_putchar(nb + 48);
	}
	return(0);
}

void my_swap(int *a, int *b) {
	int swaper;
	swaper = *a;
	*a = *b;
	*b = swaper;
}

void my_putstr(char const *str) {
	int i;
	for(i = 0; str[i] != '\0'; i += 1)
		my_putchar(str[i]);
}

int my_strlen(const char *str) {
	int i;
	while(str[i] != '\0') {
		i += 1;
	}
	return (i);
}

int my_getnbr(char const *str) {
	// need to do it
	return (0);
}

void my_sort_int_array(int *tab, int size) {
	//need to complete
}


int my_compute_power_rec(int nb, int power) {
	//need to complete
	return(0);
}
int my_compute_power_square_root(int nb) {
	//need to complete
	return(0);
}

int my_is_prime(int nb) {
	//need to complete
	return(0);
}

int my_find_prime_sup(int nb) {
	//need to complete
	return(0);
}

char *my_strcpy(char *dest, char const *src) {
	int i;
	for(i = 0; i != '\0'; i += 1)
		dest[i] = src[i];
	dest[i] = '\0';
	return(dest);
}

char my_strncpy(char *dest, char const *src, int n) {
	int i;
	for(i = 0; i != '\0' && i <= n; i += 1)
		dest[i] = src[i];
	return(*dest);
}

char my_revstr(char *str) {
	int strlen = (my_strlen(str)-1);
	char temp;
	int i;
	for(i = 0; i <= strlen; i += 1) {
		temp = str[i];
		str[strlen] = str[i];
		str[i] = temp;
		strlen -= 1;
	}
	return(*str);
}

char my_strstr(char *str, char const *to_find) {
	//to do
	return(*str);
}

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

char my_strupcase(char *str) {
	// to do
	return(*str);
}

char my_strlowcase(char *str) {
	// to do
	return(0);
}

char my_strcapitalize(char *str) {
	// to do
	return(0);
}

int my_str_isalpha(char const *str) {
	//to do
	return(0);
}

int my_str_isnum(char const *str) {
	//to do
	return(0);
}

int my_str_islower(char const *str) {
	//to do
	return(0);
}

int my_str_isupper(char const *str) {
	//to do
	return(0);
}

int my_str_isprintablble(char const *str) {
	//to do
	return(0);
}

int my_showstr(char const *str) {
	//to do
	return(0);
}

int my_showmem(char *dest, int size) {
	//to do
	return(0);
}

char my_strcat(char *dest, char const *str) {
	//to do
	return(0);
}

char my_strncat(char *dest, char const *str, int nb) {
	//to do
	return(0);
}

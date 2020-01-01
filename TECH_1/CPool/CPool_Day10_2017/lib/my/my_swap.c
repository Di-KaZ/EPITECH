/*
 ** EPITECH PROJECT, 2017
 ** my_swap
 ** File description:
 ** swap two var
 */

void my_swap(int *a, int *b) {
	int swaper;
	swaper = *a;
	*a = *b;
	*b = swaper;
}


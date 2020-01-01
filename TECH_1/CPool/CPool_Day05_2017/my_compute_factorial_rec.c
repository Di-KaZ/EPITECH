/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec
** File description:
** return the factorial of the number but with recusive call
*/
int my_compute_factorial_rec(int nb) {
	 if( nb < 0) {
		 return 1;
	 }
	 else if( nb == 0) {
		 return 0;
	 }
	 else {
		 while (nb >= 1) {
			return nb * my_compute_factorial_rec(nb - 1);
		 }
	 }
}

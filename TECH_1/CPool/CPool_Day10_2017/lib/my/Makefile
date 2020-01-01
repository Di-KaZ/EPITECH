SRC = my_compute_power_rec.c \
	  my_compute_power_square_root.c \
	  my_find_prime_sup.c \
	  my_getnbr.c \
	  my_isneg.c \
	  my_is_prime.c \
	  my_putchar.c \
	  my_put_nbr.c \
	  my_putstr.c \
	  my_revstr.c \
	  my_showmen.c \
	  my_showstr.c \
	  my_sort_int_array.c \
	  my_strcapitalize.c \
	  my_strcat.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_str_isalpha.c \
	  my_str_islower.c \
	  my_str_isnum.c \
	  my_str_isprintable.c \
	  my_str_isupper.c \
	  my_strlen.c \
	  my_strlowcase.c \
	  my_strncat.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_strstr.c \
	  my_strupcase.c \
	  my_swap.c \
	  my_get_nbr.c 

OBJ = $(SRC:.c=.o)

NAME = my


all: $(SRC) $(NAME)


$(NAME):$(OBJ)
	ar rc lib$(NAME).a $(OBJ)
	cp lib$(NAME).a ../
	mkdir -p ../../include
	cp my.h ../../include

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f lib$(NAME).a
	rm -f ../lib$(NAME).a
	rm -f ../../include/my.h

re: fclean all

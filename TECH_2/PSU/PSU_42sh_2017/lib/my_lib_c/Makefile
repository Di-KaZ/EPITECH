##
## EPITECH PROJECT, 2018
## my_lib_c
## File description:
## making the lib_c
##

SRC =	is_str_num.c \
		my_garbage_collector.c \
		my_get_nbr.c \
		my_put_nbr.c \
		my_strcmp.c \
		my_str_to_word_array.c \
		print_func.c \
		linker.c \
		my_printf.c \
		my_random.c \
		my_strcpy.c \
		my_strcat.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)

NAME = libmy_lib_c.a

CFLAGS = -Wall -Werror -Wextra -g3

all:$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re: fclean all

.PHONY:all re fclean clean

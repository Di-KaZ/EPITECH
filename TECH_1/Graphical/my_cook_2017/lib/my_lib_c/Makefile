##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = src/is_str_num.c \
	  src/my_garbage_collector.c \
	  src/my_get_nbr.c \
	  src/my_put_nbr.c \
	  src/my_strcmp.c \
	  src/my_str_to_word_array.c \
	  src/print_func.c \
	  src/my_strcp.c \
	  src/my_random.c \
	  src/my_realloc_str.c

OBJ = $(SRC:.c=.o)

NAME = libmy_lib_c.a

CFLAGS = -Wall -Werror -Wextra -I ../../include

all:$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../.

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re: fclean all

.PHONY:all re fclean clean

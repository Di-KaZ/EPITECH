##
## EPITECH PROJECT, 2017
## makefile
## File description:
## .
##

SRC = my_printf.c my_putchar.c my_putstr.c my_strlen.c \
      my_put_nbr.c print_uint.c my_strdup.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I ../../include -Wall -Werror -Wextra

NAME = libmy.a

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re: fclean all

.PHONY: all re clean fclean


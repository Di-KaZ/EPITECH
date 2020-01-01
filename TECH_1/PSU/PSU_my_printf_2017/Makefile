##
## EPITECH PROJECT, 2017
## makefile
## File description:
## .
##

SRC = my_printf.c my_putchar.c my_putstr.c my_strlen.c \
      my_put_nbr.c print_uint.c
OBJ = $(SRC:.c=.o)
NAME = libmy.a

all: $(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p include
	cp my.h include/
	mkdir -p lib
	cp $(NAME) lib/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf lib/$(NAME)
	rm -rf include/my.h

re: fclean all

.PHONY: all re clean fclean


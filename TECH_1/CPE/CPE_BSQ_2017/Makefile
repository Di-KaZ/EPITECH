##
## EPITECH PROJECT, 2017
## 
## File description:
## 
##

SRC = src/main.c  \
	  src/manage_file.c \
	  src/get_size.c \
	  src/char_star_to_char_star_star.c \
	  src/my_putstr.c \
	  src/my_putchar.c \
	  src/my_strlen.c \
	  src/print_bsq.c \
	  src/convert_bsq.c\
	  src/get_greater_square.c \
	  src/compare_value.c \
	  src/convert_charss_intss.c \
	  src/free_ressources.c \

OBJ = $(SRC:.c=.o)

NAME = bsq

CFLAGS += -I include -Wall -Werror -Wextra -g3

all: $(NAME)

$(NAME):$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean

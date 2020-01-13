##
## EPITECH PROJECT, 2017
## makefile
## File description:
## make the minishell project
##

SRC =	src/main.c \
		src/struct_filler.c \
		src/is_str_num.c \
		src/algorithm.c \
		src/algorithm_using_p.c \
		src/algorithm_p.c \
		src/convert_in_base.c

OBJ = $(SRC:.c=.o)

NAME = palindrome

CFLAGS = -g3 -Wall -Wextra -Werror

CPPFLAGS = -I include

CC = gcc

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re

##
## EPITECH PROJECT, 2018
## makefile
## File description:
## make the minishell project
##

SRC =	src/main.c \
		src/disp_prompt.c \
		src/command.c \
		src/cd_command.c \
		src/manage_signal.c \
		src/manage_env.c \
		src/setenv.c \
		src/linkers.c \
		src/unsetenv.c \
		src/chained_to_array.c \
		src/path_parser.c \
		src/format_string.c

OBJ = $(SRC:.c=.o)

NAME = mysh

CFLAGS = -I include -L lib -g -g3 -Wall -Wextra

CC = gcc

all:$(NAME)

$(NAME):$(OBJ)
	make -C ./lib/my_lib_c
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -l my_lib_c -l gnl

clean:
	make clean -C ./lib/my_lib_c
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./lib/my_lib_c
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re

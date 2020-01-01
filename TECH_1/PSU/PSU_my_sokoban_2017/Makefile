##
## EPITECH PROJECT, 2017
## 
## File description:
## 
##

SRC = src/main.c \
	  src/manage_sokoban.c \
	  src/manage_input.c \
	  src/print_map.c \
	  src/ini_object.c \
	  src/colision.c \
	  src/ini_object2.c \
	  src/my_strcmp.c \
	  src/check_box_stuck.c \
	  src/manage_error.c

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

CFLAGS += -I include -Wall -Wextra -g3 -Werror

all: $(NAME)

$(NAME):$(OBJ)
	gcc $(OBJ) -o $(NAME) -l ncurses

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all fclena clean

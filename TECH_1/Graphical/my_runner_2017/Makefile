##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

SRC = src/main.c \
	  src/ini_object.c \
	  src/ini_prlx.c \
	  src/manage_layer.c \
	  src/open_map.c \
	  src/gravity_thing.c \
	  src/player.c \
	  src/disp_map.c \
	  src/manage_life.c \
	  src/ini_map.c \
	  src/manage_menu.c \
	  src/button_menu.c \
	  src/gravity_thing2.c \
	  src/victory_or_deafeat.c \
	  src/pause_screen.c \
	  src/player_change.c \
	  src/usage_or_map.c \
	  src/print_func.c

OBJ = $(SRC:.c=.o)

CC = gcc

NAME = my_runner

all: $(NAME)

CFLAGS += -I include -Wall -Werror -g3 -Wextra

$(NAME):$(OBJ)
	make -C lib
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L lib -l c_graph_prog -l my_csfml
	@tput setaf 2; cat signature; tput sgr0

clean:
	make clean -C lib
	rm -rf $(OBJ)

fclean:clean
	make fclean -C lib
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean

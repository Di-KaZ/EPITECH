##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC = 	  src/main.c \
	  src/ini_scene.c \
	  src/ini_objs.c \
	  src/disp_scene.c \
	  src/close_window.c \
	  src/open_map.c \
	  src/pointer_table.c \
	  src/game.c \
	  src/dragndrop.c \
	  src/manage_cook.c \
	  src/client.c \
	  src/pause.c \
	  src/music.c \
	  src/ini_recipe.c \
	  src/ini_ingredients.c \
	  src/add_ingredient.c \
	  src/manage_ingredients_adding.c

OBJ = $(SRC:.c=.o)

CC = gcc

NAME = my_cook

all: $(NAME)

CFLAGS += -I include -g3 -Wall -Werror -Wextra
$(NAME):$(OBJ)
	make -C lib
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L lib/ -l my_csfml -l my_lib_c -lcsfml-graphics -lcsfml-window -lcsfml-system -lpthread -lcsfml-audio

clean:
	make clean -C lib
	rm -rf $(OBJ)

fclean:clean
	make fclean -C lib
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean

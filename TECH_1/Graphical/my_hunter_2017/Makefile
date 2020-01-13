##
## EPITECH PROJECT, 2017
## 
## File description:
## 
##

SRC = src/main.c \
	  src/manage_ia.c \
	  src/dog_move.c \
	  src/ini_ia.c \
	  src/duck_move.c \
	  src/ini_sounds.c \
	  src/titlescreen.c \
	  src/ini_title.c \
	  src/usage.c

OBJ = $(SRC:.c=.o)

CFLAGS += -I include -Wall -Werror -Wextra -g3

NAME = my_hunter

all:$(NAME)

$(NAME):$(OBJ)
	make -C lib
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -L lib -l my_csfml -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -l my
	@tput setaf 2; cat signature; tput sgr0
clean:
	make clean -C lib
	rm -rf $(OBJ)

fclean: clean
	make fclean -C lib
	rm -rf $(NAME)

re: fclean all

.PHONY: re all fclean clean

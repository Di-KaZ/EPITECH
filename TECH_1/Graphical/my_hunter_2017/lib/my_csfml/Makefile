##
## EPITECH PROJECT, 2017
## 
## File description:
## 
##

SRC = ini_csfml.c \
	  destroy_csfml.c \
	  display_csfml.c \
	  clock_csfml.c \
	  position_csfml.c

OBJ = $(SRC:.c=.o)

NAME = libmy_csfml.a

CFLAGS = -I ../../include -l my_csfml -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re: fclean all

.PHONY: clean fclean re all

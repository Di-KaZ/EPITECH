SRC = src/main.c \
	  src/print_func.c \
	  src/ini_board.c \
	  src/my_get_nbr.c \
	  src/player.c \
	  src/checker.c \
	  src/get_next_line.c \
	  src/bot_ai.c \
	  src/my_put_nbr.c \
	  src/my_garbage_collector.c \
	  src/messages.c \
	  src/win.c

OBJ = $(SRC:.c=.o)

CFLAGS += -I include -g3 -Wall -Werror -Wextra

NAME = matchstick

all: $(NAME)

$(NAME):$(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:fclean clean re all

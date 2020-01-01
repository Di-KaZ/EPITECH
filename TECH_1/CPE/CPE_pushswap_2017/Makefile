SRC = 		 src/main.c \
	  	src/my_putstr.c \
	  	src/my_strlen.c \
	   src/my_get_nbr.c \
	   src/my_put_nbr.c \
	   src/my_putchar.c \
	  		src/main2.c \
	  	 src/pushswap.c \
		      src/opt.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

CFLAGS = -I include -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean

##
## EPITECH PROJECT, 2017
## <>
## File description:
## <>
##

SRC = do-op.c

NAME = do-op


LIB = my

all:$(NAME)

$(NAME):$(SRC)
	cd ../lib/my/ && make
	gcc $(SRC) -L ../lib/ -l$(LIB) -o $(NAME)

clean:
	cd ../lib/my/ && make clean

fclean:
	cd ../lib/my/ && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re

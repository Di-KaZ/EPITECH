##
## EPITECH PROJECT, 2019
## Strace
## File description:
## Makefile
##

all: client server

client:
	(cd src/client/; make)

server:
	(cd src/server/; make)

clean:
	cd src/client && make clean
	cd src/server && make clean

fclean:
	cd src/client && make fclean
	cd src/server && make fclean

re: fclean all

.PHONY: all clean fclean re client server

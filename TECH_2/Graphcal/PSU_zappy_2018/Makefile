##
## EPITECH PROJECT, 2019
## temp_zappy
## File description:
## Makefile
##

zappy_ai:
	make -C srcs/client

zappy_server:
	make -C srcs/server

all: zappy_ai zappy_server

clean:
	make clean -C srcs/server
	make clean -C srcs/client

fclean:
	make fclean -C srcs/server
	make fclean -C srcs/client

re: fclean all

.PHONY: all clean fclean re zappy_ai zappy_server
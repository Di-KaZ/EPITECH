SRC = main.c \
	  src/flag_identifier.c \
	  src/dir.c \
	  src/get_info.c \
	  src/printer.c \
	  src/add_dir_name.c \
	  src/print_auth.c

OBJ = $(SRC:.c=.o)

NAME = my_ls

CFLAGS = -I include -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJ)
	make -C lib/
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -L lib -l my

noflag:
	gcc -c $(NAME)
	make -C lib/
	gcc -I include $(OBJ) -o $(NAME) -L lib -l my
	
clean:
	rm -rf $(OBJ)
	make clean -C lib/

fclean: clean
	rm -rf $(NAME)
	make fclean -C lib/

re: fclean all

.PHONY: all re fclean clean

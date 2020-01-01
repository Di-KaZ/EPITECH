##
## EPITECH PROJECT, 2019
## Strace
## File description:
## Makefile
##

SRC     = 	main.c			\
			initialize_client.c	\
			utils.c \
			initialize_graphical_map.c \
			initialize_player.c \
			initialize_graphical_title.c \
			initialize_graphical_display.c \
			connection_utils.c \
			update_info_thread.c \
			command_coin.c \
			assets_manager.c \
			node_texture.c \
			node_font.c \
			parallax_layer.c \
			animator.c \
			main_plus.c

SRCFILES  = $(SRC)

OBJFILES  = $(SRC:.c=.o)

NAME      = clientJ2T3

CXX = gcc -g3

CFLAGS += -Wall -Wextra -g3 -I ../../include/client -I ../../include

CPPFLAGS += -I ../../include/client -I ../../include

LDFLAGS  += -lcsfml-graphics -lcsfml-window -lcsfml-system -lpthread

all: $(NAME)

$(NAME): $(OBJFILES)
	@echo -e "\e[25;120;124mLinking binary \e[38;5;208m$(NAME)\e[39m..."
	@$(CXX) $^ -o $(NAME) $(LDFLAGS)
	@echo -e "\e[25;120;124mDone making binary \e[38;5;208m$(NAME)"
	@cp $(NAME) ../../$(NAME)

$(SRCDIR)%.o: $(SRCDIR)%.c
	@echo -e "\e[38;120;250mCompiling ($(CXX))\t\e[38;5;32m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJFILES)
	@$(RM) -rf LogicGate/*.o
	@echo -e "Removed \e[38;5;32mobject files\e[39m"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ../../$(NAME)
	@echo -e "Removed binary \e[38;5;208m$(NAME)\e[39m"

re: fclean all

.PHONY: all re clean fclean

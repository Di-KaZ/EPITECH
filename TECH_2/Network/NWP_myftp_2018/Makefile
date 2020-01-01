##
## EPITECH PROJECT, 2019
## Groundhog
## File description:
## Makefile
##

SRCDIR  = src/

SRC     =	main.c \
			tools.c \
			manage_client.c \
			run.c \
			quit_cmd.c \
			commandline_arg.c
			
SRCFILES  = $(addprefix $(SRCDIR), $(SRC))

OBJFILES  = $(addprefix $(SRCDIR), $(SRC:.c=.o))

NAME      = serverJ2T3

CXX = gcc

CXXFLAGS += -Wall -Wextra -Werror -g3

CPPFLAGS += -I include/ -Wall -Wextra -Werror -g3

LDFLAGS  += -I include/ -Wall -Wextra -Werror -g3

all: core

core: $(OBJFILES)
	@echo -e "\e[25;120;124mLinking binary \e[38;5;208m$(NAME)\e[39m..."
	@$(CXX) $^ -o $(NAME) $(LDFLAGS)
	@echo -e "\e[25;120;124mDone making binary \e[38;5;208m$(NAME)"

$(SRCDIR)%.o: $(SRCDIR)%.cpp
	@echo -e "\e[38;120;250mCompiling ($(CXX))\t\e[38;5;32m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJFILES)
	@echo -e "Removed \e[38;5;32mobject files\e[39m"


fclean: clean
	@$(RM) $(NAME)
	@echo -e "Removed binary \e[38;5;208m$(NAME)\e[39m"

re: fclean all

.PHONY: all re core graphicals games clean fclean

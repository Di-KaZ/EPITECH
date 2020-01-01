##
## EPITECH PROJECT, 2019
## Strace
## File description:
## Makefile
##

SRCDIR  = ./

SRC     = 	main.cpp \
			client.cpp \
			parse_bct.cpp

SRCFILES  = $(addprefix $(SRCDIR), $(SRC))

OBJFILES  = $(addprefix $(SRCDIR), $(SRC:.cpp=.o))

NAME      = zappy_ai

CXX = g++

CXXFLAGS += -Wall -Wextra -g3

CPPFLAGS += -I../../include

LDFLAGS  += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(NAME)
	cp $(NAME) ../../$(NAME)

$(NAME): $(OBJFILES)
	@echo -e "\e[25;120;124mLinking binary \e[38;5;208m$(NAME)\e[39m..."
	@$(CXX) $^ -o $(NAME) $(LDFLAGS)
	@echo -e "\e[25;120;124mDone making binary \e[38;5;208m$(NAME)"

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

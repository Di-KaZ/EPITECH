##
## EPITECH PROJECT, 2017
## makefile
## File description:
## Makefile root
##

SRC	=	qix.cpp \
		player.cpp \
		board.cpp \
		monster.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	lib_arcade_qix.so

CFLAGS	=	-Wall -Wextra

CXXFLAGS	=	-I ../. -I ../../libs

CXX = g++

all:	$(NAME)

$(NAME):	$(OBJ)
		@echo -e "\e[25;120;124mLinking game lib \e[38;5;208m$(NAME)\e[39m..."
		@g++ -shared -fpic -o ../$(NAME) $(SRC) $(CXXFLAGS)
		@echo -e "\e[25;120;124mDone making game \e[38;5;208m$(NAME)"

$(SRCDIR)%.o: $(SRCDIR)%.cpp
	@echo -e "\e[38;120;250mCompiling ($(CXX))\t\e[38;5;32m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f ../$(NAME)

re:	fclean all

.PHONY: all re clean fclean

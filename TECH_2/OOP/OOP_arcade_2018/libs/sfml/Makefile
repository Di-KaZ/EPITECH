##
## EPITECH PROJECT, 2017
## makefile
## File description:
## Makefile root
##

SRC	=	SFMLGraphicalHandler.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	libsfmlhandler.so

CFLAGS	=	-Wall -Wextra -Werror -g3

CXXFLAGS	=	-I ../. -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -fPIC -shared

CXX = g++

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\e[25;120;124mLinking graphical lib \e[38;5;208m$(NAME)\e[39m..."
		@g++ -shared -fpic -o ../$(NAME) $(SRC) $(CXXFLAGS)
		@echo -e "\e[25;120;124mDone making graphical lib \e[38;5;208m$(NAME)"

$(SRCDIR)%.o: $(SRCDIR)%.cpp
	@echo -e "\e[38;120;250mCompiling ($(CXX))\t\e[38;5;32m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f ../$(NAME)

re:	fclean all

.PHONY: all re clean fclean

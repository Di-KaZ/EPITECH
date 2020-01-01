##
## EPITECH PROJECT, 2019
## Groundhog
## File description:
## Makefile
##

SRCDIR  = src/

SRC     =	main.cpp \
		Factory.cpp \
		Floatclass.cpp \
		Doubleclass.cpp \
		int8class.cpp \
		int16class.cpp \
		int32class.cpp \
		BigDecimalclass.cpp \
		parsingFile.cpp \
		Command.cpp \
		instruction.cpp

SRCFILES  = $(addprefix $(SRCDIR), $(SRC))

OBJFILES  = $(addprefix $(SRCDIR), $(SRC:.cpp=.o))

NAME      = abstractVM

CXX = g++

CXXFLAGS += -Wall -Wextra -g3

CPPFLAGS += -I include/ 

LDFLAGS  += 

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

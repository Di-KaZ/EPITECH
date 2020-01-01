##
## EPITECH PROJECT, 2019
## Groundhog
## File description:
## Makefile
##

SRCDIR  = src/

SRC     = 	main.cpp \
			Parser.cpp \
			Nanotek.cpp \
			Input.cpp \
			Output.cpp \
			Chipset.cpp \
			Clock.cpp \
			False.cpp \
			True.cpp \
			LogicGate/LogicAnd.cpp \
			LogicGate/LogicOr.cpp \
			LogicGate/LogicNot.cpp \
			LogicGate/LogicXor.cpp \
			LogicGate/LogicNor.cpp \
			LogicGate/LogicNand.cpp \

SRCFILES  = $(addprefix $(SRCDIR), $(SRC))

OBJFILES  = $(addprefix $(SRCDIR), $(SRC:.cpp=.o))

NAME      = nanotekspice

CXX = g++

CXXFLAGS += -Wall -Wextra -Werror -g3

CPPFLAGS += -Iinclude -Iinclude/LogicGate

LDFLAGS  += 

all: $(NAME)

$(NAME): $(OBJFILES)
	@echo -e "\e[25;120;124mLinking binary \e[38;5;208m$(NAME)\e[39m..."
	@$(CXX) $^ -o $(NAME) $(LDFLAGS)
	@echo -e "\e[25;120;124mDone making binary \e[38;5;208m$(NAME)"

$(SRCDIR)%.o: $(SRCDIR)%.cpp
	@echo -e "\e[38;120;250mCompiling ($(CXX))\t\e[38;5;32m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJFILES)
	@$(RM) -rf LogicGate/*.o
	@echo -e "Removed \e[38;5;32mobject files\e[39m"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "Removed binary \e[38;5;208m$(NAME)\e[39m"

re: fclean all

.PHONY: all re clean fclean

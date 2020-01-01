##
## EPITECH PROJECT, 2019
## Groundhog
## File description:
## Makefile
##

SRCDIR  = core/

SRC     =	ArcadeHandler.cpp \
			main.cpp

SRCFILES  = $(addprefix $(SRCDIR), $(SRC))

OBJFILES  = $(addprefix $(SRCDIR), $(SRC:.cpp=.o))

NAME      = arcade

CXX = g++

CXXFLAGS += -Wall -Wextra -Werror -g3

CPPFLAGS += -Icore/ -Ilibs/ -Igames/

LDFLAGS  += -ldl

all: core
	@echo -e "\e[25;120;124mMaking Libs \e[38;5;208m$(NAME)\e[39m..."
	@make --no-print-directory -C libs/
	@echo -e "\e[25;120;124mMaking Games \e[38;5;208m$(NAME)\e[39m..."
	@make --no-print-directory -C games/

core: $(OBJFILES)
	@echo -e "\e[25;120;124mLinking binary \e[38;5;208m$(NAME)\e[39m..."
	@$(CXX) $^ -o $(NAME) $(LDFLAGS)
	@echo -e "\e[25;120;124mDone making binary \e[38;5;208m$(NAME)"

$(SRCDIR)%.o: $(SRCDIR)%.cpp
	@echo -e "\e[38;120;250mCompiling ($(CXX))\t\e[38;5;32m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

graphicals:
	@make --no-print-directory -C libs/

games:
	@make --no-print-directory -C games/

clean:
	@$(RM) -rf $(OBJFILES)
	@$(RM) -rf LogicGate/*.o
	@echo -e "Removed \e[38;5;32mobject files\e[39m"
	@make clean --no-print-directory -C games/
	@echo -e "Removed \e[38;5;32mobject files in games\e[39m"
	@make clean --no-print-directory -C libs/
	@echo -e "Removed \e[38;5;32mobject files in libs\e[39m"


fclean: clean
	@$(RM) $(NAME)
	@echo -e "Removed binary \e[38;5;208m$(NAME)\e[39m"
	@make fclean --no-print-directory -C games/
	@echo -e "Removed games libs \e[38;5;208m$(NAME)\e[39m"
	@make fclean --no-print-directory -C libs/
	@echo -e "Removed graphicals libs \e[38;5;208m$(NAME)\e[39m"

re: fclean all

.PHONY: all re core graphicals games clean fclean

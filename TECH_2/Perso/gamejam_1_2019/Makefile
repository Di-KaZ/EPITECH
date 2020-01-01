##
## EPITECH PROJECT, 2019
## Santa!!!
## File description:
## Makefile
##

SRCDIR  = src/

OBJDIR  = obj/

SRC     = \
main.cpp \
StateMachine.cpp \
AssetsManager.cpp \
Game.cpp \
InputManager.cpp \
StateSplash.cpp \
sprite_manipulation.cpp \
StateMenu.cpp \
StateLvl1.cpp \
Score.cpp \
Player.cpp \
GameObject.cpp \
Bailiff.cpp \
Poele.cpp \
StateScoreboard.cpp\

SRCFILES  = $(addprefix $(SRCDIR), $(SRC))

OBJFILES  = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

NAME      = BSNP

CXXFLAGS += -Wall -Wextra -W

CPPFLAGS += -Iinclude

LDFLAGS  += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(NAME)

$(NAME): $(OBJFILES)
	@echo -e "\e[25;120;124mLinking binary \e[38;5;208m$(NAME)\e[39m..."
	@$(CXX) $^ -o $(NAME) $(LDFLAGS)
	@echo -e "\e[25;120;124mDone making binary \e[38;5;208m$(NAME)"

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@echo -e "\e[38;120;250mCompiling ($(CXX))\t\e[38;5;32m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJFILES)
	@echo -e "Removed \e[38;5;32mobject files\e[39m"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "Removed binary \e[38;5;208m$(NAME)\e[39m"

re: fclean all

.PHONY: all re clean fclean

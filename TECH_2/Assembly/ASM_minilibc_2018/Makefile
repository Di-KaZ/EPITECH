##
## EPITECH PROJECT, 2019
## Groundhog
## File description:
## Makefile
##

SRCDIR  = src/

SRC     = 	strlen.s \
			strchr.s \
			strcmp.s \
			strncmp.s \
			memset.s \
			memcpy.s \
			strcasecmp.s \
			rindex.s \

SRCFILES  = $(addprefix $(SRCDIR), $(SRC))

OBJFILES  = $(addprefix $(SRCDIR), $(SRC:.s=.o))

NAME      = libasm.so

AS = nasm

ASFLAGS = -f elf64 -shared

CXX = gcc

CXXFLAGS += -Wall -Wextra -nostdlib -Werror -shared -fpic

CPPFLAGS += 

LDFLAGS  += 

all: $(NAME)

$(NAME): $(OBJFILES)
	@echo -e "\e[25;120;124mLinking binary \e[38;5;208m$(NAME)\e[39m..."
	@$(CXX) -shared -fpic -nostdlib $(OBJFILES) -o $(NAME)
	@echo -e "\e[25;120;124mDone making binary \e[38;5;208m$(NAME)"

clean:
	@$(RM) -rf $(OBJFILES)
	@echo -e "Removed \e[38;5;32mobject files\e[39m"

fclean: clean
	@$(RM) $(NAME)
	@echo -e "Removed binary \e[38;5;208m$(NAME)\e[39m"

re: fclean all

.PHONY: all re clean fclean

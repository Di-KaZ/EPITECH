##
## EPITECH PROJECT, 2019
## Groundhog
## File description:
## Makefile
##

NAME      = deBruijn

all: $(NAME)
SRC = src/Lib.hs \
	app/Main.hs \

$(NAME):$(SRC)
	stack build
	stack build --copy-bins --local-bin-path .
	cp deBruijn-exe $(NAME)

#	cp ./.stack-work/install/x86_64-linux/lts-13.8/8.6.3/bin/deBrujin-exe ./$(NAME)
clean:
	stack clean
	rm .stack-work deBruijn.cabal -rf

fclean: clean
	@$(RM) $(NAME)
	@rm deBruijn-exe -rf
	@echo -e "Removed binary \e[38;5;208m$(NAME)\e[39m"

re: fclean all

.PHONY: all re clean fclean

FILE="Makefile"

SRCS=$(ls src)

LIBS_DIR=$(sed -n '/LIBS_DIR;/p' $1 | awk -F ';' '{print$2}')

SOURCES_DIR=$(sed -n '/PROJECT_DIR;/p' $1 | awk -F ';' '{print$2}')

PROJECT_DIR=$(sed -n '/PROJECT_DIR;/p' $1 | awk -F ';' '{print$2}')

CC=$(sed -n '/CC;/p' $1 | awk -F ';' '{print$2}')

HEADER_DIR=$(sed -n '/HEADER_DIR;/p' $1 | awk -F ';' '{print$2}')

CFLAGS_DIR=$(sed -n '/CFLAGS_DIR;/p' $1 | awk -F ';' '{print$2}')

NAME=$(sed -n '/EXEC;/p' $1 | awk -F ';' '{print$2}')

printf "##\n## EPITECH PROJECT, 2017\n## Makefile\n## File description:\n## Makefile\n##\n\n" >> $FILE

printf "CFLAGS = %s\n\n" $CFLAGS_DIR >> $FILE

printf "CC = %s\n\n" $CC>> $FILE

printf "SRC = %s\n\n" "$SRCS" >> $FILE

printf "OBJS = \$(SRC:.c=.o)\n" >> $FILE

printf "NAME = %s\n\n" $NAME >> $FILE

printf "all:\$(NAME)\n\n\$(NAME):\$(OBJS)\n\t\$(CC) \$(CPPFLAGS) \$(CFLAGS) \$(OBJS) -o \$(NAME)\n\nclean:\n\trm -rf \$(OBJ)\n\nfclean: clean\n\trm-rf \$(NAME)\nre: fclean all\n\n.PHONY: all fclean re\n" >> $FILE

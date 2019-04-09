##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME		=	my_defender

CC		=	gcc

SRC		=	$(wildcard src/*.c)

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-I./include

LDFLAGS 	=	-Wall -Wextra -W

LFLAGS		=	-L./lib/my -lmy -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-graphics -lm

all:	$(NAME)

%.o:	%.c
			@$(CC) $(CFLAGS) $(LDFLAGS) $(LFLAGS) -g3 -c -o $@ $<
			@if [ -a $@ ]; then echo -e "\033[0;32m[OK]    \033[1;32m" $< "\033[0m"; else echo -e "\033[0;31m[KO]    \033[1;31m" $< "\033[0m"; fi;

$(NAME):	$(OBJ)
			@echo -e "\033[0;34m[OK]     \033[1;34mObj's files successfully compiled!\033[0m"
			@make -sC lib/my
			@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LFLAGS)
			@if [ -a $(NAME) ]; then echo -e "\033[0;34m[OK]    \033[1;34m" $(NAME) "successfully created!\n\033[1;33m"; else echo -e "\033[0;31m[KO]    \033[1;31m" $(NAME) "not compiled\033[0m"; fi;
			@if [ -a $(NAME) ]; then echo -e "███╗   ███╗ ██╗   ██╗       ██████╗  ███████╗ ███████╗ ███████╗ ███╗   ██╗ ██████╗  ███████╗ ██████╗"; fi;
			@if [ -a $(NAME) ]; then echo -e "████╗ ████║ ╚██╗ ██╔╝       ██╔══██╗ ██╔════╝ ██╔════╝ ██╔════╝ ████╗  ██║ ██╔══██╗ ██╔════╝ ██╔══██╗"; fi
			@if [ -a $(NAME) ]; then echo -e "██╔████╔██║  ╚████╔╝        ██║  ██║ █████╗   █████╗   █████╗   ██╔██╗ ██║ ██║  ██║ █████╗   ██████╔╝"; fi
			@if [ -a $(NAME) ]; then echo -e "██║╚██╔╝██║   ╚██╔╝         ██║  ██║ ██╔══╝   ██╔══╝   ██╔══╝   ██║╚██╗██║ ██║  ██║ ██╔══╝   ██╔══██╗"; fi
			@if [ -a $(NAME) ]; then echo -e "██║ ╚═╝ ██║    ██║ ███████╗ ██████╔╝ ███████╗ ██║      ███████╗ ██║ ╚████║ ██████╔╝ ███████╗ ██║  ██║"; fi
			@if [ -a $(NAME) ]; then echo -e "╚═╝     ╚═╝    ╚═╝ ╚══════╝ ╚═════╝  ╚══════╝ ╚═╝      ╚══════╝ ╚═╝  ╚═══╝ ╚═════╝  ╚══════╝ ╚═╝  ╚═╝\033[0m"; fi

clean:
			@make -sC lib/my clean
			@rm -f $(OBJ)

fclean:	clean
			@make -sC lib/my fclean
			@rm -f $(shell find . -name "*~")
			@rm -f $(shell find . -name "vgcore.*")
			@rm -f $(NAME)
			@echo -e "\033[0;33m[OK]     \033[1;33msuccessfully cleaned!\033[0m"

re:	fclean all

.PHONY:	all clean fclean re

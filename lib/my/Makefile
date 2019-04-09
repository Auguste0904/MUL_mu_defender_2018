##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile of libmy
##

NAME	=	libmy.a

CC	=	gcc

SRC	=	my_atoi.c		\
		my_itoa.c		\
		my_malloc.c		\
		my_revstr.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_strcmp.c		\
		my_strdup.c		\
		my_strlen.c

CFLAGS	+=	-Wall -Wextra -I./../../include

OBJ	=	$(SRC:.c=.o)


all:	$(NAME)

%.o:	%.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@if [ -a $@ ]; then echo -e "\033[0;32m[OK]    \033[1;32m" $< "\033[0m"; else echo -e "\033[0;31m[KO]    \033[1;31m" $< "\033[0m"; fi;

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@if [ -a $(NAME) ]; then echo -en "\033[0;34m[OK]    \033[1;34m" $(NAME) "successfully compiled!\n\033[0m"; else echo -e "\033[0;31m[KO]    \033[1;31m" $(NAME) "not compiled!\n\033[0m"; fi;

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all debug clean fclean re

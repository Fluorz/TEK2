##
## EPITECH PROJECT, 2018
## PSU_2017_malloc
## File description:
##        Makefile
##

CC	=	gcc

CFLAGS	=	-W -Wno-deprecated-declarations -I./

NAME	=	libmy_malloc.so

SRC	=	malloc.c	\
		utils.c		\
		realloc.c	\

OBJ	=	malloc.o	\
		utils.o		\
		realloc.o	\

all	:	$(NAME)

$(NAME)	:
	$(CC) -c $(SRC) -fPIC $(CFLAGS)
	$(CC) --shared -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

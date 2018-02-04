##
## EPITECH PROJECT, 2018
## pool
## File description:
##        Makefile
##

NAME	= menger

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./menger.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

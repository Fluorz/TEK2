NAME	= lemipc

CC	= gcc

RM	= rm -f

SRCS	= ./src/algo_movement.c \
	  ./src/create_ressources.c \
	  ./src/delete_ressources.c \
	  ./src/check_neighboor.c \
	  ./src/main.c \
	  ./src/stored_board.c	\
	  ./src/semaphore_check.c	\
	  ./src/tools.c	\
	  ./src/position.c	\
	  ./src/ia.c	\
	  ./src/get.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
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

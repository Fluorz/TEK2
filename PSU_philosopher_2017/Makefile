CC		=	gcc

CFLAGS		+=	-W -Wall -Wextra -I./inc

LDFLAGS		=	-L./lib -lriceferee -pthread

SRCS		=	src/main.c \
			src/philo.c \
			src/actions.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	philo

all		:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)

re		:	fclean all

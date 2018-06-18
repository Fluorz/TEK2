NAME	= strace

CC	= gcc

RM	= rm -f

SRCS	= $(wildcard src/*.c) \
	  $(wildcard src/specific_functions/*.c)

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

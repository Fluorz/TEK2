NAME	= my_convert_temp

CC	= g++

RM	= rm -f

SRCS	= ./temp_conversion.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

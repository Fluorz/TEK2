NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= $(wildcard src/*.cpp) \
	  $(wildcard src/*/*.cpp) \
	  $(wildcard src/masterProcess/CLI/*.cpp) \

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/
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

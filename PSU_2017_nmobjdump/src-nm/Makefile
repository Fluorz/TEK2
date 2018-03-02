NAME	= my_nm

CC	= gcc

RM	= rm -f

SRCS	= ./Elf_32/elf_32.c \
	  ./Elf_32/get_flag.c \
	  ./Elf_64/elf_64.c \
	  ./Elf_64/get_flag.c \
	  ./check_version.c \
	  ./common/list.c \
	  ./common/sort_list.c \
	  ./common/utils_list.c \
	  ./main.c

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

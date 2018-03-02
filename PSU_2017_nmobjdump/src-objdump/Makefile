NAME	= my_objdump

CC	= gcc

RM	= rm -f

SRCS	= ./Elf_32/print_header.c \
	  ./Elf_32/print_source.c \
	  ./Elf_32/flags.c	\
	  ./Elf_32/fill.c	\
	  ./Elf_64/print_header.c \
	  ./Elf_64/print_source.c \
	  ./Elf_64/flags.c	\
	  ./Elf_64/fill.c	\
	  ./common/utils.c	\
	  ./common/other.c	\
	  ./check_version.c \
	  ./objdump.c

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

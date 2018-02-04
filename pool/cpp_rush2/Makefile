NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./src/objects/Box.cpp \
	  ./src/objects/GiftPaper.cpp \
	  ./src/objects/Wrap.cpp \
	  ./src/objects/Object.cpp \
	  ./src/objects/Teddy.cpp \
	  ./src/objects/LittlePony.cpp \
	  ./src/objects/Toy.cpp \
	  ./src/workstation/IConvoyorBelt.cpp \
	  ./src/workstation/ITable.cpp \
	  ./src/workstation/PapaXmasConvoyorBelt.cpp \
	  ./src/workstation/PapaXmasTable.cpp \
	  ./src/elf/PapaXmasElf.cpp \
	  ./src/elf/IElf.cpp \
	  ./UnitTests.cpp \
	  ./src/workstation/ConveyorBeltRand.cpp \
	  ./src/workstation/TableRand.cpp \
	  ./src/logger/Error.cpp \
	  ./src/logger/Logger.cpp \
	  ./src/XML/XML.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/objects -I./include/elf -I./include/workstation \
	-I./include/logger/ -I./include/XML/ -std=c++11
CPPFLAGS += -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

tests_run:
	make -C tests/
	./tests/units

.PHONY: all clean fclean re tests_run

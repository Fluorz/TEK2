NAME	= units

CC	= g++

RM	= rm -f

SRCS	= ../src/objects/Box.cpp \
	  ../src/objects/GiftPaper.cpp \
	  ../src/objects/Wrap.cpp \
	  ../src/objects/Object.cpp \
	  ../src/objects/Teddy.cpp \
	  ../src/objects/LittlePony.cpp \
	  ../src/objects/Toy.cpp \
	  ../src/workstation/IConvoyorBelt.cpp \
	  ../src/workstation/ITable.cpp \
	  ../src/workstation/PapaXmasConvoyorBelt.cpp \
	  ../src/workstation/PapaXmasTable.cpp \
	  ../src/elf/PapaXmasElf.cpp \
	  ../src/elf/IElf.cpp \
	  ../src/workstation/ConveyorBeltRand.cpp \
	  ../src/workstation/TableRand.cpp \
	  ./test.cpp \
	  ../src/logger/Logger.cpp \
	  ../src/logger/Error.cpp \
	  ../src/XML/XML.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ../include/objects -I../include/elf -I../include/workstation -I../include/logger -I../include/XML -std=c++11 -lcriterion
CPPFLAGS += -W -Wall -Wextra -Werror --coverage

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

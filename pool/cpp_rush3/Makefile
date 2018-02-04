##
## EPITECH PROJECT, 2018
## cpp_rush3
## File description:
##        Makefile
##

CC	=	g++

SRC	=	src/main.cpp 	\
		src/base/CMD/CMD.cpp			\
		src/base/CPUCore/CPUCore.cpp		\
		src/modules/CPUModule/CPUModule.cpp	\
		src/modules/UserModule/User.cpp		\
		src/modules/RamModule/Ram.cpp		\
		src/modules/NetworkModule/Network.cpp	\
		src/modules/MonitorCore/MonitorCore.cpp	\
		src/modules/DiskModule/Disk.cpp		\
		src/modules/TemperatureModule/Temperature.cpp \
		src/modules/BatteryModule/Battery.cpp	\
		src/modules/PartitionsModule/Partitions.cpp	\
		tests/to_test.cpp			\
		src/ncurses/Display.cpp			\

NAME	=	turfu

OBJ	=	$(SRC:.cpp=.o)


CPPFLAGS +=	-I./src/base/CMD/		\
		-I./src/base/CPUCore/ 		\
		-I./src/base/Maths/		\
		-I./src/modules/		\
		-I./src/modules/CPUModule/	\
		-I./src/modules/MonitorCore/	\
		-I./src/modules/NetworkModule/	\
		-I./src/modules/RamModule/	\
		-I./src/modules/UserModule/	\
		-I./src/modules/BatteryModule/	\
		-I./src/modules/DiskModule/	\
		-I./src/modules/PartitionsModule/	\
		-I./src/modules/TemperatureModule/	\
		-I./src/ncurses/	\
		-lncurses

CPPFLAGS += -W -Wall -Wextra -std=gnu++11

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

tests_run	:
	make -C tests/
	./tests/units

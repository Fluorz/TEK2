NAME	= units

CC	=	g++

RM	= rm -f

SRC	=	../src/base/CMD/CMD.cpp			\
		../src/base/CPUCore/CPUCore.cpp		\
		../src/modules/CPUModule/CPUModule.cpp	\
		../src/modules/UserModule/User.cpp		\
		../src/modules/RamModule/Ram.cpp		\
		../src/modules/NetworkModule/Network.cpp	\
		../src/modules/MonitorCore/MonitorCore.cpp	\
		../src/modules/DiskModule/Disk.cpp		\
		../src/modules/TemperatureModule/Temperature.cpp \
		../src/modules/BatteryModule/Battery.cpp	\
		../src/modules/PartitionsModule/Partitions.cpp	\
		./main_tests.cpp				\
		./to_test.cpp					\

CPPFLAGS +=	-I../src/base/CMD/		\
		-I../src/base/CPUCore/ 		\
		-I../src/base/Maths/		\
		-I../src/modules/		\
		-I../src/modules/CPUModule/	\
		-I../src/modules/MonitorCore/	\
		-I../src/modules/NetworkModule/	\
		-I../src/modules/RamModule/	\
		-I../src/modules/UserModule/	\
		-I../src/modules/BatteryModule/	\
		-I../src/modules/DiskModule/	\
		-I../src/modules/PartitionsModule/	\
		-I../src/modules/TemperatureModule/

OBJS	= $(SRC:.cpp=.o)

CPPFLAGS += -W -Wall -Wextra -Werror --coverage -std=c++11 -lcriterion -ftest-coverage

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)
	cd ../ ; find . -name "*.gcno" -type f -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

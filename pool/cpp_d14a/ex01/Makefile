SRC = test.cpp \
	  Errors.cpp

CXX = g++
CXXFLAGS = -W -Wall -Wextra -std=c++03
LDFLAGS =
NAME = ex00

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

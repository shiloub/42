NAME = btc
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = parsing.cpp \
		main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean 
		make all



NAME = harl
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Harl.cpp \
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



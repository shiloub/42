NAME = human
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \
		main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

#%.o : %.cpp
#	$(CC) $(CF) -o $@ -c $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean 
		make all



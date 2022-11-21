NAME = openspace
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Bureaucrat.cpp \
		main.cpp \
		Form.cpp \
		ShrubberyCreationForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp


OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME) *_shrubbery

re : fclean 
		make all



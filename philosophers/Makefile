NAME = philo
CC = gcc
CFLAGS = -pthread #-Wall -Wextra -Werror
SRC = main.c \
		parse.c \
		ft_atoi.c \


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $^ $(CFLAGS) 

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all


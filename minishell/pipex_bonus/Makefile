NAME = test
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
SRC = exec_command.c \
	ft_split.c \
	ft_strncmp.c \
	ft_strlen.c \
	ft_strjoin.c \
	ft_strdup.c \
	
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all


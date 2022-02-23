NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRC = pipex.c \
	utils.c \
	ft_split.c \
	ft_strncmp.c \
	ft_strlen.c \
	ft_strjoin.c \
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean :
	rm -rf *.o

fclean : clean
	rm -f $(NAME)

re : fclean all


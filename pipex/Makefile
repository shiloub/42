NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c \
	utils.c \
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^

libft/libft.a :
	cd libft && make && make clean && cd ..

%.o : %.c
	$(CC) -o $@ -c $^ $(CFLAGS) 

clean :
	rm -rf *.o

libfclean :
	rm -f libft/libft.a

fclean : clean libfclean
	rm -f $(NAME)

re : fclean all


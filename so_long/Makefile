NAME = test
CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS =
SRC = parsing.c
            
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all


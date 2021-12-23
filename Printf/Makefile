NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c\
      display.c\
      treat.c\
            
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar crs $@ $^

%.o : %.c
	$(CC) -o $@ -c $^ $(CFLAGS) 

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all


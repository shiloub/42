NAME = test
CC = gcc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS =
SRC = srcs/main.c srcs/set.c srcs/parsing.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/print_map.c srcs/open_door.c srcs/move.c srcs/finish.c srcs/check_map.c
#SRC = test.c\
# 	check_map.c\
# 	gnl/get_next_line.c\
# 	gnl/get_next_line_utils.c\
            
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 

%.o: %.c printf/libftprintf.a
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ 


clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

#-fsanitize=address
#-fsanitize=address
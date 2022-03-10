NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = srcs/main.c \
		srcs/set.c \
		srcs/parsing.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/print_map.c \
		srcs/open_door.c \
		srcs/move.c \
		srcs/finish.c \
		srcs/check_map.c \
		srcs/check_map_ft.c \

            
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) printf/libftprintf.a
	$(CC) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ 

printf/libftprintf.a :
	cd printf && make && make clean && cd ..

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

#-fsanitize=address
#-fsanitize=address
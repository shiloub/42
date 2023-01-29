NAME = test
CC = gcc
CFLAGS = #-Wall -Wextra -Werror
SRC = main.c \
		get_next_line_utils.c \
		get_next_line.c \
		readfile.c \
		check.c \
		free.c \
		parse.c \
		utils.c \
		set_map.c \
		check_map.c \
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $^ -o $(NAME) 

libft/libft.a :
	cd libft && make && make clean && cd ..
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

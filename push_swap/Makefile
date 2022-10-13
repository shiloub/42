NAME_PS = push_swap
NAME_CK = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_PS = exec_move.c \
	free.c \
	intlst.c \
	push_swap.c \
	operation.c \
	position.c \
	set_move_rotate_reverse.c \
	set_move.c \
	parsing.c \
	write_op.c \
	sort_minor.c \
	ft_atoi_exit.c \
	check_parsing.c \
	find_pos.c \

SRC_CK = free.c \
	intlst.c \
	checker.c \
	operation.c \
	parsing.c \
	check_parsing.c \
	ft_atoi_exit.c \
	strlst.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \



OBJ_PS = $(SRC_PS:.c=.o)
OBJ_CK = $(SRC_CK:.c=.o)

all : $(NAME_PS)

bonus : $(NAME_CK)

$(NAME_PS) : $(OBJ_PS) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CK) : $(OBJ_CK) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^ 

%.o : %.c
	$(CC) -o $@ -c $^ $(CFLAGS) 

libft/libft.a :
	cd libft && make && make clean && cd ..

clean : libclean
	rm -rf $(OBJ_CK) $(OBJ_PS)

fclean : clean libfclean
	rm -rf $(NAME_PS) $(NAME_CK)

libclean :
	rm -f libft/*.o

libfclean : libclean
	rm -f libft/libft.a

re : fclean all


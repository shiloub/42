# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontant <amontant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 18:53:28 by amontant          #+#    #+#              #
#    Updated: 2022/03/09 18:53:17 by amontant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c\
      display.c\
	  display2.c\
	  count.c\
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


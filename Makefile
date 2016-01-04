# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 15:26:59 by gahubaul          #+#    #+#              #
#    Updated: 2016/01/04 18:42:39 by rlemarch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

FLAG=-Wall -Wextra -Werror

SRC= check_error.c check_tetri.c error_print.c main2.c resolve.c \

OBJ=$(SRC:.c=.o)

$(NAME): 
	gcc $(FLAG) -c $(SRC)
	gcc $(OBJ) -L. -lft -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

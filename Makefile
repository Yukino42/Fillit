# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 15:26:59 by gahubaul          #+#    #+#              #
#    Updated: 2015/12/10 15:27:05 by gahubaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG = -Wall -Wextra -Werror
SRC =  
	main.c \

all = $(NAME)

$(NAME) = 
	gcc $(FLAG) $(SRC) -o $(NAME)

clean =
	rm -rf $(SRC.0)

fclean = clean
	rm -rf $(NAME)

re = fclean re
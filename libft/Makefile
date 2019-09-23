# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 10:34:56 by aabouibr          #+#    #+#              #
#    Updated: 2018/10/15 16:12:54 by aabouibr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
OBJECTS =  *.o

FLAGS = -Wall -Wextra -Werror

$(NAME) :
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
all:$(NAME)
clean:
	/bin/rm -f $(OBJECTS)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all


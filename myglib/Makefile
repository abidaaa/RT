# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 13:09:20 by aabouibr          #+#    #+#              #
#    Updated: 2019/08/01 13:25:12 by aabouibr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOM=libglib.a
SRC= init_win.c rgb_to_int.c
OBJ=$(SRC:.c=.o)

all: $(NOM)

$(NOM): $(OBJ)
		ar -r $(NOM) $(OBJ)
		ranlib $(NOM)

clean:
		rm -f $(NOM) $(OBJ) *~

re: clean all
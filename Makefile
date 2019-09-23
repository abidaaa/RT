# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 12:08:32 by aabouibr          #+#    #+#              #
#    Updated: 2019/09/16 18:55:16 by aabouibr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
RTV1FILES = ./srcs/ft_camera_functions.c\
		./srcs/ft_casting.c\
		./srcs/ft_key_hooks.c\
		./srcs/ft_light.c\
		./srcs/ft_new_objects.c\
		./srcs/ft_parse_config_file.c\
		./srcs/ft_rotations.c\
		./srcs/ft_shapes_intersections.c\
		./srcs/ft_tools.c\
		./srcs/ft_vector_math_equations.c\
		./srcs/ft_vector_math_products.c\
		./srcs/ft_vector_math_operations.c\
		./srcs/ft_objects_rotations.c\
		./srcs/ft_shadow_rotations.c\
		./srcs/ft_normals.c\
		./srcs/main.c\
		./srcs/ft_init_var.c\
		./srcs/ft_get_translation_and_normal.c\
		./srcs/ft_add_objects.c\
		./srcs/ft_check_objects.c\
		./srcs/ft_check_functions.c\

LIBDIRS = -L./libft -L./minilibx -L./myglib
LIBS = -lft -lglib -lmlx
INCLUDES = -I includes
FLAGS = -framework OpenGl -framework AppKit -Wall -Werror -Wextra

all: $(NAME)
$(NAME):
		make -C libft
		make -C minilibx
		make -C myglib
		gcc $(FLAGS) $(RTV1FILES) $(INCLUDES) $(LIBDIRS) $(LIBS) -o $(NAME)
clean:
		make clean -C libft
		make clean -C minilibx
		make clean -C myglib
		rm -f $(NAME)
fclean: clean
		make fclean -C libft
re: fclean all
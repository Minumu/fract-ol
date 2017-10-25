#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:47:54 by tshevchu          #+#    #+#              #
#    Updated: 2017/10/24 16:48:37 by tshevchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

LIBMLX = -lmlx -framework OpenGL -framework AppKit

OBJECTS = fractals.o init_structs.o key_processing.o main.o putpixel_black.o putpixel_colorful.o threads.o threads_functions.o

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT)
	@gcc $(OBJECTS) $(FLAGS) $(LIBFT)libft.a $(LIBMLX) -o $(NAME)
	@echo "\x1B[01;34m>>>>>FRACTOL IS READY!!<<<<<"

%.o: ./%.c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -f $(OBJECTS)
	@echo "\x1B[01;90m>>>CLEAN FRACTOL & LIBFT OBJ<<<"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\x1B[01;93m>>>EVERYTHING IS CLEAR:)<<<"

re: fclean all
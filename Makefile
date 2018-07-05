# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atemunov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/30 17:15:04 by atemunov          #+#    #+#              #
#    Updated: 2018/07/02 10:09:07 by atemunov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./libft/libft.a ./minilibx_macos/libmlx.a

SRC = src/main.c \
	  src/helping_functions.c \
	  src/draw_lines.c \
	  src/parser.c \

FRAMEWORKS = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

OBJ = *.o

READY = @echo "\033[0;32mFdF Executable ready to use!"

all : $(NAME)

$(NAME):
	@make -C libft/
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(SRC)  $(INCLUDES) -o $(NAME)
	@echo "Succesfully created FdF Executable"
	$(READY)

clean:
	make -C libft fclean
	make -C mlx clean

fclean:
	rm -rf $(NAME)

re: fclean all

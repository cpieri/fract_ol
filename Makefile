# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/09 09:09:41 by cpieri            #+#    #+#              #
#    Updated: 2018/02/15 14:27:47 by cpieri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

FRAME	=	-L./minilibx -lmlx -framework OpenGl -framework AppKit

CPPFLAGS=	-Iinclude

FLAGSFT	=	-L./libft -lft

SRC_PATH=	src

OBJ_PATH=	obj

SRC_NAME=	main.c			\
			mandelbrot.c	\
			img.c			\
			event.c			\
			mouse.c			\
			zoom.c			\
			thread.c		\
			color.c			\
			burning_ship.c	\
			exit.c

OBJ_NAME=	$(SRC_NAME:.c=.o)

SRC		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ		=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY:	all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			@make -C ./minilibx
			$(CC) $(CFLAGS) -lpthread -o $(NAME) $(OBJ) $(CPPFLAGS) $(FLAGSFT) $(FRAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
			@mkdir $(OBJ_PATH) 2> /dev/null || true
			@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
			@echo "cleaning"
			@make clean -C ./libft/
			@make clean -C ./minilibx/
			@/bin/rm -f $(OBJ)
			@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:		clean
			@make fclean -C ./libft/
			@/bin/rm -f $(NAME)

re:			fclean all

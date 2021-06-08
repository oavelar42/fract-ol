# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 19:51:56 by oavelar           #+#    #+#              #
#    Updated: 2021/06/08 21:27:16 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fractol

OS		:= $(shell uname)

CC		= gcc 

CFLAGS		= -Wall -Wextra -Werror -Imlx

INCLUDES	= -Iincludes/ -I$(MINILIBX_DIR)

LIBFT_DIR	= libft/

LIBFT_A		= libft/libft.a

SRC_DIR		= srcs/

SRC_FILES	= 	main.c \
				image.c \
				render.c \
				move.c \
				view.c \
				color.c \
				fractal_name.c \
				fractal_burn.c \
				fractal_julia.c \
				fractal_mandel.c
		
SRC		= $(addprefix $(SRC_DIR), $(SRC_FILES))

GREEN		= \033[1;32m
BLUE		= \033[0;34m
RED		= \033[1;31m
COLOR_OFF	= \033[0m

ifeq ($(OS), Linux)
	MINILIBX_DIR = mlx_linux
	MLXFLAG = -lm -lbsd -lX11 -lXext
endif

ifeq ($(OS), Darwin)
	MINILIBX_DIR = minilibx_mac
	MLXFLAG = -lmlx -framework OpenGL -framework AppKit
endif

MINILIBX_A	= $(MINILIBX_DIR)/libmlx.a

all: libraries $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Building Fract-ol$(COLOR_OFF)"
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(LIBFT_A) $(MINILIBX_A) $(MLXFLAG) -o $(NAME)
	@echo "$(GREEN)miniRT done!$(COLOR_OFF)"

libraries:
	@echo "$(BLUE)Building libraries....$(COLOR_OFF)"
	make -C $(LIBFT_DIR)
	make -C $(MINILIBX_DIR)
	@echo "$(GREEN)Libraries built$(COLOR_OFF)"

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)

fclean:
	@rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)
	@echo "\033[0;31m ---- all cleared! ---- \033[0m"

re: fclean all

.PHONY: all clean fclean re libraries bonus

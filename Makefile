# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 16:32:14 by jlebre            #+#    #+#              #
#    Updated: 2023/03/01 18:10:48 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -I. -O3 -Wall -Wextra -Werror -g -fsanitize=address
MLXFLAGS_LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = @rm -fr
NAME = cub3d
SRCS = main.c ft_exit.c key_press.c init_vars.c render.c printf_fd.c \
		init_image.c ft_abs.c raycast.c draw.c utils.c mini_map.c\
		\
		parse/parse.c parse/parse_vars.c parse/parse_file.c parse/load_xpm.c \
		\
		allocs/allocs.c allocs/frees.c \
		\
		check_map/algo_utils.c check_map/algorithm.c check_map/check_map.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIB = .

all: $(NAME) lib

$(NAME): $(OBJS) lib
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS_LINUX) $(LIBFT) -o $(NAME)
	@echo "\033[0;32mCub3d Compiled!\033[0m"

lib:
	@make -C $(LIBFT_PATH)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@echo "\033[0;31m.o Files Removed!\033[0m"
	
fclean: clean
	$(RM) $(NAME) 
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[0;31mCub3d Removed!\033[0m"

re: fclean all

a: 
	make re && make clean && ./cub3d basic.cub

.PHONY: all clean fclean re

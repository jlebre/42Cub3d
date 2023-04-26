# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 00:30:45 by mtavares          #+#    #+#              #
#    Updated: 2023/04/26 22:13:26 by mtavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE_NAME	=	allocs/frees.c \
				allocs/allocs.c \
				check_map/algorithm.c \
				check_map/algo_utils.c \
				check_map/check_map.c \
				draw/draw_utils.c \
				draw/draw_walls.c \
				draw/textures.c \
				draw/pixel.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				key/key_press.c \
				key/movement.c \
				key/switches.c \
				parse/algorithm.c \
				parse/parse.c \
				parse/parse_file.c \
				parse/parse_vars.c \
				str/str.c \
				str/utils1.c \
				str/utils2.c \
				init/init_image.c \
				init/init_textures.c \
				init/init_vars.c \
				utils/ft_abs.c \
				utils/ft_exit.c \
				utils/utils.c \
				raycast/mini_map.c \
				raycast/raycast.c \
				raycast/render.c \
				main.c \

SRCS_DIR	=	srcs

SRCS		=	$(addprefix $(SRCS_DIR)/, $(FILE_NAME))

OBJS		=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	=	objs

PRINTF		=	libs/printf_fd/libprintf_fd.a

MLX			=	mlx_linux/libmlx_Linux.a

NAME		=	cub3d

CC			=	cc

INC			=	-I includes -I libs/printf_fd/include  -I mlx_linux

CFLAGS		=	-Wall -Wextra -Werror $(INC) -g# -fsanitize=address

RM			=	rm -rf

LIBS_FLAGS	= -L libs/printf_fd -l printf_fd -Lmlx_linux -lmlx_Linux -L /usr/lib -lXext -lX11 -lm -lz

all:		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME):	$(PRINTF) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)


$(PRINTF):
	@make -sC libs/printf_fd

$(MLX):
	@make -sC mlx_linux

clean:
	@$(RM) $(OBJS_DIR)
	@make clean -sC libs/printf_fd
	@make clean -sC mlx_linux

fclean:		clean
	@$(RM) $(NAME)
	@make fclean -sC libs/printf_fd

a:
	@make re && make clean && ./cub3d basic.cub

re:			fclean all

.PHONY: all clean fclean re a

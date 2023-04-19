# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 00:30:45 by mtavares          #+#    #+#              #
#    Updated: 2023/04/20 00:30:46 by mtavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(SRCS_DIR)/allocs/frees.c \
				$(SRCS_DIR)/allocs/allocs.c \
				$(SRCS_DIR)/check_map/algorithm.c \
				$(SRCS_DIR)/check_map/algo_utils.c \
				$(SRCS_DIR)/check_map/check_map.c \
				$(SRCS_DIR)/draw/draw_utils.c \
				$(SRCS_DIR)/draw/draw_walls.c \
				$(SRCS_DIR)/draw/textures.c \
				$(SRCS_DIR)/gnl/get_next_line.c \
				$(SRCS_DIR)/gnl/get_next_line_utils.c \
				$(SRCS_DIR)/key/key_press.c \
				$(SRCS_DIR)/key/movement.c \
				$(SRCS_DIR)/key/switches.c \
				$(SRCS_DIR)/parse/algorithm.c \
				$(SRCS_DIR)/parse/parse.c \
				$(SRCS_DIR)/parse/parse_file.c \
				$(SRCS_DIR)/parse/parse_vars.c \
				$(SRCS_DIR)/str/str.c \
				$(SRCS_DIR)/str/utils1.c \
				$(SRCS_DIR)/str/utils2.c \
				$(SRCS_DIR)/raycast/init_image.c \
				$(SRCS_DIR)/raycast/init_vars.c \
				$(SRCS_DIR)/raycast/ft_abs.c \
				$(SRCS_DIR)/raycast/ft_exit.c \
				$(SRCS_DIR)/raycast/main.c \
				$(SRCS_DIR)/raycast/mini_map.c \
				$(SRCS_DIR)/raycast/raycast.c \
				$(SRCS_DIR)/raycast/render.c \
				$(SRCS_DIR)/raycast/utils.c \

SRCS_DIR	=	srcs

OBJS		=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	=	objs



PRINTF		=	libs/printf_fd/libprintf_fd.a

MLX			=	mlx_linux/libmlx_Linux.a

NAME		=	cub3d

CC			=	cc

INC			=	-Iincludes -Ilibs/printf_fd/include -I/usr/include -Imlx_linux

CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address

RM			=	rm -rf

PRINTF_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

MLX_FLAGS		= -Llibs/printf_fd -lprintf_fd

all:		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -O3 -c $< -o $@

$(NAME):	$(PRINTF) $(MLX) $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME) $(PRINTF_FLAGS) $(MLX_FLAGS)


$(PRINTF):
		@make -C libs/printf_fd

$(MLX):
		@make -C mlx_linux

clean:
		@$(RM) $(OBJS_DIR)
		@make clean -C libs/printf_fd
		@make clean -C mlx_linux

fclean:		clean
		@$(RM) $(NAME)
		@make fclean -C libs/printf_fd

a:
	@make re && make clean && ./cub3d basic.cub

re:			fclean all

.PHONY: all clean fclean re a

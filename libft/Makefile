# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 11:24:43 by jlebre            #+#    #+#              #
#    Updated: 2022/09/01 18:41:27 by jlebre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM		= @rm -fr

NAME	= libft.a
LIB		= .

SRCS	= ft_strlen.c ft_strchr.c ft_strrchr.c \
			ft_atoi.c ft_strdup.c ft_itoa.c\
			ft_substr.c ft_strjoin.c ft_split.c\
			get_next_line.c get_next_line_utils.c\
			ft_printf.c func_extra.c func_extra1.c\
			ft_strjoin_without_newline.c ft_strdup_without_newline.c ft_remove_newline.c\

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(LIB1) $(NAME) $(OBJS)
			@$(LIB2) $(NAME)
			@echo "\033[0;32mLibft Compiled!\033[0m"

.c.o:
			@$(CC) $(CFLAGS) -I$(LIB) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)
			@echo "\033[0;31m.o Files Removed!\033[0m"

fclean:		clean
			$(RM) $(NAME)
			@echo "\033[0;31mLibft.a Removed!\033[0m"

re:			fclean all

.PHONY:		all clean fclean re 

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: resilva <resilva@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 16:02:54 by resilva           #+#    #+#              #
#    Updated: 2024/03/15 02:08:01 by resilva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRC			= src/so_long.c \
				src/map.c \
				src/utils.c \

OBJS		= ${SRC:.c=.o}

CC			= gcc
MAKE		= make -C
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g 
INCLUDE		= -I ./include
LIBFT_PATH	= libs/libft
MLX_PATH	= /usr/local/lib
LIBFT		= -L ${LIBFT_PATH} -lft
MLX			= -L ${MLX_PATH} -lmlx -lmlx -lXext -lX11 -lm

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${MAKE} ${LIBFT_PATH}
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}
		${MAKE} ${LIBFT_PATH} clean

fclean: clean
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
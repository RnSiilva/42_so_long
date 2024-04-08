# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: resilva <resilva@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 16:02:54 by resilva           #+#    #+#              #
#    Updated: 2024/04/08 12:25:31 by resilva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

NAME		= so_long

SRC			= src/main.c \
				src/check_map.c \
				src/controls.c \
				src/destroy_game.c \
				src/map.c \
				src/utils.c \
				src/init_game.c \

#SRC:= $(wildcard src/*.c)
OBJS		= ${SRC:.c=.o}

CC			= gcc
MAKE		= make -C
RM			= rm -f

PRINTF		= LC_NUMERIC="en_US.UTF-8" printf
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDE		= -I ./include
LIBFT_PATH	= libs/libft
MLX_PATH	= libs/minilibx-linux
LIBFT		= -L ${LIBFT_PATH} -lft
MLX			= -L ${MLX_PATH} -lmlx -lmlx -lXext -lX11 -lm

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME): ${OBJS}
		@echo "$(MAGNETA)Compiling:$(RESET) $(GREEN)libft/*$(RESET)"
		${MAKE} ${LIBFT_PATH}
		
		@echo "$(MAGNETA)Compiling:$(RESET) $(GREEN)mlx/*$(RESET)"
		${MAKE} ${MLX_PATH} 2> /dev/null
		
		@echo "$(CYAN)🔗 Linking...$(RESET)" 
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

		@echo "$(GREEN)🎉 Compilation is done! 🎉$(RESET)"

clean:
		@${RM} ${OBJS}

		${MAKE} ${MLX_PATH} clean
		${MAKE} ${LIBFT_PATH} clean
		@echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(OBJS)$(RESET)"

fclean: clean
		${MAKE} ${LIBFT_PATH} clean

		@echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)"
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
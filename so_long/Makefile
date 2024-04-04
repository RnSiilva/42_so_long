# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: resilva <resilva@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 16:02:54 by resilva           #+#    #+#              #
#    Updated: 2024/04/04 03:25:30 by resilva          ###   ########.fr        #
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
		@$(PRINTF) "$(MAGNETA)Compiling:$(RESET) $(GREEN)libft/*$(RESET)\n"
		${MAKE} ${LIBFT_PATH}
		
		@$(PRINTF) "$(MAGNETA)Compiling:$(RESET) $(GREEN)mlx/*$(RESET)\n"
		${MAKE} ${MLX_PATH} 2> /dev/null
		
		@$(PRINTF) "$(CYAN)🔗 Linking: $(RESET) $(CFLAGS) $(GREEN)*$(RESET)\n" 
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

		@$(PRINTF) "$(GREEN)🎉 Compilation is done! 🎉$(RESET)\n"

clean:
		@$(PRINTF) "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(OBJS)$(RESET)\n"
		${RM} ${OBJS}

		${MAKE} ${MLX_PATH} clean
		${MAKE} ${LIBFT_PATH} clean

fclean: clean
		${MAKE} ${LIBFT_PATH} clean

		@$(PRINTF) "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)\n"
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
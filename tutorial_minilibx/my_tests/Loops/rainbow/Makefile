NAME		= tutorial#
INC			= -I ./include#
UNAME		= $(shell uname)#	# UNAME will get the OS name, this will help define behaviors for certain OS's
MLX_PATH	= ../../../minilibx-linux
CFLAGS		= -Wall -Werror -Wextra -g#
MLX			= -L ${MLX_PATH} -lmlx -lmlx -lXext -lX11 -lm#
SRC			= $(wildcard *.c)#	# list your source files
OBJ			= $(SRC:%.c=%.o)#	# convert source files to binary list

ifeq ($(UNAME), Darwin) # iMac / iOS
	CC = gcc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD) # FreeBSD
	CC = clang
else #Linux and others...
	CC = gcc
endif

all: $(NAME)

$(NAME): $(OBJ) show
	make -C $(MLX_PATH)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(INCLUDE) $(MLX)

clean:
	rm -f $(OBJ)
	make -C $(MLX_PATH) clean 

fclean: clean
	rm -f $(NAME)

re: fclean all

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"

PHONY: show fclean clean all

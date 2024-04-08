/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:22:24 by resilva           #+#    #+#             */
/*   Updated: 2024/04/08 16:11:57 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "so_long.h"

/* Colors */
# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"

/* Key events */
# define ON_KEYPRESS	2
# define KEYPRESS_MASK	3
# define ON_DESTROY		17
# define DESTROY_MASK	0
# define ON_EXPOSE		12
# define EXPOSE_MASK	32768
# define MLX_ERROR		1

/* Path images */
# define WALL_PATH		"./img/wall.xpm"
# define CHAR_PATH		"./img/player.xpm"
# define CHARL_PATH		"./img/left.xpm"
# define CHARPLATE_PATH	"./img/player_plate.xpm"
# define CHARCOIN_PATH	"./img/player_coin.xpm"
# define CHAR_EXIT_PATH	"./img/player_exit.xpm"
# define COIN_PATH		"./img/collect.xpm"
# define PLATE_PATH		"./img/plate.xpm"
# define EXIT_PATH		"./img/door_close.xpm"
# define EXIT_OPEN_PATH	"./img/door_open.xpm"
# define FREESP_PATH	"./img/freesp.xpm"

/* Sprite size */
# define SIZE 32

/* To check the tiles */
# define TILE "01PCE"

typedef enum e_tile
{
	SPACE = '0',
	WALL = '1',
	PLAYER = 'P',
	COIN = 'C',
	EXIT = 'E',
	EXIT_OPEN = 'K',
	PLATE = 'L',
	PLAYER_PLATE = 'M',
	PLAYER_EXIT = 'N',
	PLAYER_COIN = 'Q'
}				t_tile;

typedef enum e_key
{
	ESC = 65307,
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
}				t_key;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_img
{
	void	*img;
	int		*pixels;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		movements;
	int		active;
}				t_img;
typedef struct s_map
{
	char	**tiles;
	t_pos	pos;
	int		coins;
	int		exit;
	int		player;
}				t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_pos	player_pos;
	t_pos	exit_pos;
	t_pos	next_pos;
	t_img	i_wall;
	t_img	i_player;
	t_img	i_player_plate;
	t_img	i_player_exit;
	t_img	i_player_coin;
	t_img	i_collectible;
	t_img	i_exit;
	t_img	i_exit_open;
	t_img	i_free_space;
	t_img	i_plate;
	int		moves;
	int		coin;
}				t_game;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:22:24 by resilva           #+#    #+#             */
/*   Updated: 2024/03/29 01:18:14 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "so_long.h"

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
# define CHAR_PATH		"./img/char.xpm"
# define COLLECT_PATH	"./img/collect.xpm"
# define EXIT_PATH		"./img/exit.xpm"
# define FREESP_PATH	"./img/freesp.xpm"

/* Sprite size */
# define SIZE 50

/* To check the tiles */
# define TILE "01PCE"

typedef enum	e_tile
{
	SPACE = '0',
	WALL = '1',
	PLAYER = 'P',
	COIN = 'C',
	EXIT = 'E',
}				t_tile;

typedef enum	e_key
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

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_img
{
	void	*img;
	int		*pixels;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		movements;
}				t_img;
typedef struct	s_map
{
	char	**tiles;
	t_pos	pos;
	int		coins;
	int		exit;
	int		player;
}				t_map;

typedef struct	s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_pos	player_pos;
	t_pos	next_pos;
	t_img	wall;
	t_img	character;
	t_img	collectible;
	t_img	exit;
	t_img	free_space;
	int		moves;
	int		coin;
}				t_game;

#endif

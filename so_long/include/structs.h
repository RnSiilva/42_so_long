/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:22:24 by resilva           #+#    #+#             */
/*   Updated: 2024/03/14 23:50:45 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "so_long.h"

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_img
{
	void	*ptr;
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
}				t_game;

#endif
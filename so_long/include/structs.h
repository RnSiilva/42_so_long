/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:22:24 by resilva           #+#    #+#             */
/*   Updated: 2024/03/14 15:26:02 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_game
{
	char	**map;
	t_pos	player_pos;
}				t_game;

#endif
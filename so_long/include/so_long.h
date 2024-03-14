/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:27:57 by resilva           #+#    #+#             */
/*   Updated: 2024/03/14 15:30:14 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "structs.h"

void	initialize_game(t_game *game, const char *map_file);
void	move_player(t_game *game, char direction);
void	display_game(t_game *game);

#endif
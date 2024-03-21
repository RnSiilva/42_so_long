/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:27:57 by resilva           #+#    #+#             */
/*   Updated: 2024/03/18 03:31:58 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "structs.h"

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# include "../libs/libft/libft.h"
# include "../libs/libft/get_next_line/get_next_line_bonus.h"

/*void	initialize_game(t_game *game, const char *map_file);
void	move_player(t_game *game, char direction);
void	display_game(t_game *game);*/

void	read_map(t_game *game, char *file);
void	check_filename(char	*file);
void	check_map(t_game *game);
int		exit_error(t_game *game, char *msg);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:27:57 by resilva           #+#    #+#             */
/*   Updated: 2024/03/29 00:32:49 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "structs.h"

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/libft/get_next_line/get_next_line_bonus.h"

/*void	initialize_game(t_game *game, const char *map_file);
void	move_player(t_game *game, char direction);
void	display_game(t_game *game);*/

void	check_filename(char	*file);
void	check_map(t_game *game);
void	read_map(t_game *game, char *file);
void	render_map(t_game *game, t_map *map);
void	render_tile(t_game *game, t_pos	p);


int		exit_error(t_game *game, char *msg);
void	clean_tiles(char **tiles);

int		flood_fill(t_map *map, t_pos curr, char **path);

void	launch_mlx(t_game *game, t_map *map);
void	load_sprites(t_game *game);
t_img	new_sprite(void	*mlx_ptr, char *path);

int	destroy_game(t_game *game);
int	keypress(int key, t_game *game);
int	move_render(t_game *game);

t_tile	get_tile(t_game *game, t_pos pos);


#endif
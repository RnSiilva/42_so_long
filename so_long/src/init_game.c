/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:04:39 by resilva           #+#    #+#             */
/*   Updated: 2024/03/29 01:30:32 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_mlx(t_game *game, t_map *map)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_error(game, "Error when starting MLX");
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	map->pos.x * SIZE, map->pos.y * SIZE, "so_long");
	if (!game->mlx_ptr)
		exit_error(game, "Error creating window");
}

void	load_sprites(t_game *game)
{
	game->wall = new_sprite(game->mlx_ptr, WALL_PATH);
	game->character = new_sprite(game->mlx_ptr, CHAR_PATH);
	game->collectible = new_sprite(game->mlx_ptr, COLLECT_PATH);
	game->exit = new_sprite(game->mlx_ptr, EXIT_PATH);
	game->free_space = new_sprite(game->mlx_ptr, FREESP_PATH);
}

t_img	new_sprite(void	*mlx_ptr, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img.x, &img.y);
	return (img);
}

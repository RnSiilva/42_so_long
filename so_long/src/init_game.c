/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:04:39 by resilva           #+#    #+#             */
/*   Updated: 2024/04/08 15:56:34 by resilva          ###   ########.fr       */
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
	game->i_wall = new_sprite(game->mlx_ptr, WALL_PATH);
	game->i_player = new_sprite(game->mlx_ptr, CHAR_PATH);
	game->i_player_plate = new_sprite(game->mlx_ptr, CHARPLATE_PATH);
	game->i_player_exit = new_sprite(game->mlx_ptr, CHAR_EXIT_PATH);
	game->i_player_coin = new_sprite(game->mlx_ptr, CHARCOIN_PATH);
	game->i_collectible = new_sprite(game->mlx_ptr, COIN_PATH);
	game->i_plate = new_sprite(game->mlx_ptr, PLATE_PATH);
	game->i_exit = new_sprite(game->mlx_ptr, EXIT_PATH);
	game->i_exit_open = new_sprite(game->mlx_ptr, EXIT_OPEN_PATH);
	game->i_free_space = new_sprite(game->mlx_ptr, FREESP_PATH);
}

t_img	new_sprite(void	*mlx_ptr, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img.x, &img.y);
	return (img);
}

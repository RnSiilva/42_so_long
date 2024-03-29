/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:32:57 by resilva           #+#    #+#             */
/*   Updated: 2024/03/29 00:35:50 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_game *game)
{
	if (!game->wall.img)
		return ;
	mlx_destroy_image(game->mlx_ptr, game->wall.img);
	mlx_destroy_image(game->mlx_ptr, game->character.img);
	mlx_destroy_image(game->mlx_ptr, game->collectible.img);
	mlx_destroy_image(game->mlx_ptr, game->exit.img);
	mlx_destroy_image(game->mlx_ptr, game->free_space.img);
}

void	clean_tiles(char **tiles)
{
	int	i;

	i = 0;
	if (!tiles || !tiles[i])
		return ;
	while (tiles[i])
		free (tiles[i++]);
	free (tiles);
}

void	clean_map(t_map *map)
{
	if (!map)
		return ;
	clean_tiles(map->tiles);
	free (map);
}

void	clean_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		clean_map(game->map);
	destroy_image(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

int	destroy_game(t_game *game)
{
	clean_game(game);
	exit(EXIT_SUCCESS);
}
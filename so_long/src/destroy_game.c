/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:32:57 by resilva           #+#    #+#             */
/*   Updated: 2024/04/08 15:58:35 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_game *game)
{
	if (!game->i_wall.img)
		return ;
	mlx_destroy_image(game->mlx_ptr, game->i_wall.img);
	mlx_destroy_image(game->mlx_ptr, game->i_player.img);
	mlx_destroy_image(game->mlx_ptr, game->i_collectible.img);
	mlx_destroy_image(game->mlx_ptr, game->i_exit.img);
	mlx_destroy_image(game->mlx_ptr, game->i_free_space.img);
	mlx_destroy_image(game->mlx_ptr, game->i_player_exit.img);
	mlx_destroy_image(game->mlx_ptr, game->i_player_plate.img);
	mlx_destroy_image(game->mlx_ptr, game->i_exit_open.img);
	mlx_destroy_image(game->mlx_ptr, game->i_plate.img);
	mlx_destroy_image(game->mlx_ptr, game->i_player_coin.img);
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
	if (game->map->tiles[game->next_pos.y][game->next_pos.x] == EXIT_OPEN)
		ft_printf(GREEN "Congratulations! you completed the game 🥳\n" RESET);
	else
		ft_printf(RED "Game closed by player!\n" RESET);
	clean_game(game);
	exit(EXIT_SUCCESS);
}

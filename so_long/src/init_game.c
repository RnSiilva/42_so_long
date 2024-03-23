/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:04:39 by resilva           #+#    #+#             */
/*   Updated: 2024/03/21 20:18:28 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_mlx(t_game *game, t_map *map)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_error(game, "Error when starting MLX");
	game->win_ptr = mlx_new_window(game->mlx_ptr, map->pos.x * SIZE, map->pos.y * SIZE, "so_long");
	if (!game->mlx_ptr)
		exit_error(game, "Error creating window");
}
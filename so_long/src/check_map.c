/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:27:40 by resilva           #+#    #+#             */
/*   Updated: 2024/03/21 01:37:34 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_format(t_map *map)
{
	size_t	rows;
	int	i;

	i = -1;
	rows = ft_strlen(map->tiles[0]);
	
}

static bool	check_walls(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->pos.y)
		if (map->tiles[i][0] != WALL || map->tiles[i][map->pos.x - 1] != WALL)
			return (false);
	i = -1;
	while (++i < map->pos.x)
		if (map->tiles[0][i] != WALL || map->tiles[map->pos.y - 1][i] != WALL)
			return (false);
	return (true);
}

static bool	check_tiles(t_game *game, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->pos.y)
	{
		if (map->tiles[i][0] != 1 || map->tiles[i][map->pos.x - 1] != 1)	
		
	}
}

void	check_map(t_game *game)
{
	if (!game->map->pos.y)
		exit_error(game, "Map is empty!");
	if (!check_format(game->map))
		exit_error(game, "Map isn't rectangular");
	if (!check_walls(game->map))
}

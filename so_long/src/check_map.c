/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:27:40 by resilva           #+#    #+#             */
/*   Updated: 2024/03/15 19:06:07 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_format(t_map *map)
{
	int	rows;
	int	i;

	rows = ft_strlen(map->tiles[0]);
	
}

static bool	check_walls(t_map *map)
{
	int	i;
	int	j;

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
	if (!check_format(game->map));
		exit_error(game, "Map isn't rectangular");
	if (!check_walls(game->map))
}

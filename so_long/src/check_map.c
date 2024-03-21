/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:27:40 by resilva           #+#    #+#             */
/*   Updated: 2024/03/21 01:53:23 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_format(t_map *map)
{
	size_t	rows;
	size_t	rows;
	int	i;

	i = -1;
	rows = ft_strlen(map->tiles[0]);
	i = -1;
	while (++i < map->pos.y - 1)
		if (ft_strlen(map->tiles[i]) != rows)
			return (false);
	map->pos.x = (int)rows;
	return (true);
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
	int	j;

	i = -1;
	while (++i < map->pos.y)
	{
		j = -1;
		while (++j < map->pos.x)
		{
			if (map->tiles[i][j] == PLAYER)
			{
				map->player++;
				game->player_pos = (t_pos){j,i};
			}
			else if (map->tiles[i][j] == COIN)
				map->coins++;
			else if (map->tiles[i][j] == EXIT)
				map->exit++;
			else if (!ft_strchr(TILE, map->tiles[i][j]))
				return (false);
		}
	}
	return (PLAYER == 1 && EXIT == 1 && map->coins);
}

static int	check_path(t_game *game, t_map *map)
{
	char	**tiles;
	int		check;
	int		i;

	tiles = ft_calloc(map->pos.y + 1, sizeof(char *));
	if (!tiles)
		exit_error(game, "Malloc error");
	i = -1;
	while (map->tiles[++i])
	{
		tiles[i] = ft_strdup(map->tiles[i]);
		if (!tiles[i])
		{
			clean_tiles(tiles);
			exit_error(game, "Malloc error");
		}
	}
	check = flood_fill(map, game->player_pos, tiles);
	clean_tiles(tiles);
	return (check);
}

void	check_map(t_game *game)
{
	if (!game->map->pos.y)
		exit_error(game, "Map is empty!");
	if (!check_format(game->map))
	if (!check_format(game->map))
		exit_error(game, "Map isn't rectangular");
	if (!check_walls(game->map))
		exit_error(game, "Map not sorrounded by walls");
	if (!check_tiles(game, game->map))
		exit_error(game, "Map has invalid tiles");
	if (!check_path(game, game->map))
		exit_error(game, "Map has invalid path");
}

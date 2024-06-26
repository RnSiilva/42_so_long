/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:48:11 by resilva           #+#    #+#             */
/*   Updated: 2024/03/29 01:27:22 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(t_game *game, char *msg)
{
	clean_game(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void	check_filename(char	*file)
{
	int	i;

	i = ft_strlen(file);
	if (i <= 4)
		exit_error(NULL, "Invalid file name.");
	else if (!ft_strnstr(file + i - 4, ".ber", 4))
		exit_error(NULL, "Invalid file extension.");
}

t_tile	get_tile(t_game *game, t_pos pos)
{
	return (game->map->tiles[pos.y][pos.x]);
}

int	flood_fill(t_map *map, t_pos curr, char **path)
{
	static int	coins = 0;
	static int	exit = 0;

	if (path[curr.y][curr.x] == WALL)
		return (0);
	else if (path[curr.y][curr.x] == COIN)
		coins++;
	else if (path[curr.y][curr.x] == EXIT)
		exit++;
	path[curr.y][curr.x] = WALL;
	flood_fill(map, (t_pos){curr.x + 1, curr.y}, path);
	flood_fill(map, (t_pos){curr.x - 1, curr.y}, path);
	flood_fill(map, (t_pos){curr.x, curr.y + 1}, path);
	flood_fill(map, (t_pos){curr.x, curr.y - 1}, path);
	return (map->coins == coins && exit == 1);
}

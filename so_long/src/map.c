/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:07:04 by resilva           #+#    #+#             */
/*   Updated: 2024/03/19 19:58:14 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*create_map(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	ft_bzero(map, sizeof(t_map));
	return (map);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;
	int		rows;

	if (!line)
		return (0);
	i = -1;
	rows = ++game->map->pos.y;
	temporary = ft_calloc(rows + 1, sizeof(char *));
	if (!temporary)
		exit_error(game, "Malloc failed");
	temporary[rows] = NULL;
	while (++i < rows - 1)
		temporary[i] = game->map->tiles[i];
	temporary[i] = line;
	if (game->map->tiles)
		free(game->map->tiles);
	game->map->tiles = temporary;
	return (1);
}

void	read_map(t_game *game, char *file)
{
	char	*line;
	int		fd;

	game->map = create_map();
	if (!game->map)
		exit_error(game, "Map reading failure");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(game, "File opening failed");
	while (1)
	{
		line = ft_strtrim(get_next_line(fd), "\n");
		if (!add_line(game, line))
			break;
		free(line);
	}
	close (fd);
}

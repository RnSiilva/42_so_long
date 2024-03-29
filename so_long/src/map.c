/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:07:04 by resilva           #+#    #+#             */
/*   Updated: 2024/03/29 00:48:43 by resilva          ###   ########.fr       */
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
	char	**temp;
	int		i;
	int		rows;

	if (!line)
		return (0);
	i = -1;
	rows = ++game->map->pos.y;
	temp = ft_calloc(rows + 1, sizeof(char *));
	if (!temp)
		exit_error(game, "Malloc failed");
	temp[rows] = NULL;
	while (++i < rows - 1)
		temp[i] = game->map->tiles[i];
	temp[i] = ft_strdup(line);
	if (game->map->tiles)
		free(game->map->tiles);
	game->map->tiles = temp;
	//clean_tiles(temporary);
	return (1);
}

void	read_map(t_game *game, char *file)
{
	char	*line;
	char	*clean_line;
	int		fd;

	game->map = create_map();
	if (!game->map)
		exit_error(game, "Map reading failure");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(game, "File opening failed");
	while (1)
	{
		line = get_next_line(fd);
		clean_line = ft_strtrim(line, "\n");
		free(line);
		if (!add_line(game, clean_line))
			break;
		free(clean_line);
	}
	close (fd);
}

void	render_tile(t_game *game, t_pos	p)
{
	if (game->map->tiles[p.y][p.x] == WALL)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->wall.img, (p.x * SIZE), (p.y * SIZE));
	else if (game->map->tiles[p.y][p.x] == COIN)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->collectible.img, (p.x * SIZE), (p.y * SIZE));
	else if (game->map->tiles[p.y][p.x] == PLAYER)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->character.img, (p.x * SIZE), (p.y * SIZE));
	else if (game->map->tiles[p.y][p.x] == EXIT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->exit.img, (p.x * SIZE), (p.y * SIZE)); 
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->free_space.img, (p.x * SIZE), (p.y * SIZE));
}

void	render_map(t_game *game, t_map *map)
{
	t_pos	position;

	position.y = -1;
	while (++position.y < map->pos.y)
	{
		position.x = -1;
		while (++position.x < map->pos.x)
			render_tile(game, position);
	}
}

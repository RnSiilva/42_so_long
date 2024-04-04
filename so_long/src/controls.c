/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:31:01 by resilva           #+#    #+#             */
/*   Updated: 2024/04/04 01:01:57 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int key, t_game *game)
{
	if (key == ESC)
		destroy_game(game);
	else if (key == W || key == UP)
		game->next_pos = (t_pos){game->player_pos.x, game->player_pos.y - 1};
	else if (key == S || key == DOWN)
		game->next_pos = (t_pos){game->player_pos.x, game->player_pos.y + 1};
	else if (key == A || key == LEFT)
		game->next_pos = (t_pos){game->player_pos.x - 1, game->player_pos.y};
	else if (key == D || key == RIGHT)
		game->next_pos = (t_pos){game->player_pos.x + 1, game->player_pos.y};
	return (0);
}

// void	player_move(t_game *game, t_map *map)
// {
// 	t_tile			next_tile;
// 	static t_tile	previous = SPACE;
// 	next_tile = get_tile(game, game->next_pos);
// 	if (next_tile == COIN || next_tile == PLATE)
// 		map->tiles[game->next_pos.y][game->next_pos.x] = PLAYER_PLATE;
// 	else if (next_tile == EXIT)
// 		map->tiles[game->next_pos.y][game->next_pos.x] = PLAYER_EXIT;
// 	else
// 		map->tiles[game->next_pos.y][game->next_pos.x] = PLAYER;

// 	if (previous == PLAYER_PLATE || previous == COIN)
// 		map->tiles[game->player_pos.y][game->player_pos.x] = PLATE;
// 	else if (previous == PLAYER_EXIT)
// 		map->tiles[game->player_pos.y][game->player_pos.x] = EXIT;
// 	else
// 		map->tiles[game->player_pos.y][game->player_pos.x] = SPACE;
// 	render_tile(game, game->player_pos);
// 	render_tile(game, game->next_pos);
// 	game->player_pos = game->next_pos;
// 	previous = map->tiles[game->next_pos.y][game->next_pos.x];
// }

void	player_move(t_game *game, t_map *map)
{
	static t_tile	previous = SPACE;
	t_tile			next_tile;

	next_tile = get_tile(game, game->next_pos);
	if (next_tile == COIN || next_tile == PLATE)
		map->tiles[game->next_pos.y][game->next_pos.x] = PLAYER_PLATE;
	else if (next_tile == EXIT)
		map->tiles[game->next_pos.y][game->next_pos.x] = PLAYER_EXIT;
	else
		map->tiles[game->next_pos.y][game->next_pos.x] = PLAYER;
	if (previous == PLAYER_PLATE)
		map->tiles[game->player_pos.y][game->player_pos.x] = PLATE;
	else if (previous == PLAYER_EXIT)
		map->tiles[game->player_pos.y][game->player_pos.x] = EXIT;
	else
		map->tiles[game->player_pos.y][game->player_pos.x] = SPACE;
	render_tile(game, game->next_pos);
	render_tile(game, game->player_pos);
	game->player_pos = game->next_pos;
	previous = map->tiles[game->player_pos.y][game->player_pos.x];
}

static bool	check_move(t_game *game, t_pos next)
{
	if (get_tile(game, next) == WALL)
		return (0);
	else if (game->player_pos.x == next.x && game->player_pos.y == next.y)
		return (0);
	return (1);
}

void	put_image_exit_open(t_game *game, t_pos exit_pos)
{
	if (get_tile(game, exit_pos) == EXIT_OPEN)
		return ;
	game->map->tiles[exit_pos.y][exit_pos.x] = EXIT_OPEN;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->i_exit_open.img, (exit_pos.x * SIZE), (exit_pos.y * SIZE));
}

int	move_render(t_game *game)
{
	if (!check_move(game, game->next_pos))
		return (0);
	ft_printf("Moves: %d\n", ++game->moves);
	if (get_tile(game, game->next_pos) == COIN)
		game->coin++;
	else if (get_tile(game, game->next_pos) == EXIT_OPEN \
		&& game->coin == game->map->coins)
		destroy_game(game);
	player_move(game, game->map);
	if (game->coin == game->map->coins)
		put_image_exit_open(game, game->exit_pos);
	return (0);
}

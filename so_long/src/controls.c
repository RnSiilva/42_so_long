/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 22:31:01 by resilva           #+#    #+#             */
/*   Updated: 2024/03/29 01:30:03 by resilva          ###   ########.fr       */
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

void	player_move(t_game *game, t_map *map)
{
	static t_tile	previous = SPACE;

	map->tiles[game->player_pos.y][game->player_pos.x] = previous;
	if (get_tile(game, game->next_pos) == COIN)
		previous = SPACE;
	else
		previous = map->tiles[game->next_pos.y][game->next_pos.x];
	map->tiles[game->next_pos.y][game->next_pos.x] = PLAYER;
	render_tile(game, (t_pos){game->player_pos.x, game->player_pos.y});
	render_tile(game, (t_pos){game->next_pos.x, game->next_pos.y});
	game->player_pos = game->next_pos;
}

static bool	is_same_place(t_pos curr, t_pos next)
{
	return (curr.x == next.x && curr.y == next.y);
}

static bool	check_move(t_game *game)
{
	return (!is_same_place(game->player_pos, game->next_pos) \
		&& get_tile(game, game->next_pos) != WALL);
}

int	move_render(t_game *game)
{
	if (!check_move(game))
		return (0);
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(++game->moves, 1);
	ft_putstr_fd("\n", 1);
	if (get_tile(game, game->next_pos) == COIN)
		game->coin++;
	else if (get_tile(game, game->next_pos) == EXIT \
		&& game->coin == game->map->coins)
	{
		ft_putstr_fd("Congratulations! You completed the game.\n", 1);
		destroy_game(game);
	}
	player_move(game, game->map);
	return (0);
}

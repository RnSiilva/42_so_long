/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:00:39 by resilva           #+#    #+#             */
/*   Updated: 2024/03/29 14:37:35 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(char *file)
{
	t_game	game;

	ft_bzero (&game, sizeof(t_game));
	read_map (&game, file);
	check_map(&game);
	launch_mlx(&game, game.map);
	load_sprites(&game);
	render_map(&game, game.map);
	mlx_hook(game.win_ptr, ON_DESTROY, DESTROY_MASK, destroy_game, &game);
	mlx_hook(game.win_ptr, ON_KEYPRESS, KEYPRESS_MASK, keypress, &game);
	mlx_loop_hook(game.mlx_ptr, move_render, &game);
	mlx_loop(game.mlx_ptr);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Use: ./so_long path_to_map_file.ber");
	check_filename(av[1]);
	init_game(av[1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:00:39 by resilva           #+#    #+#             */
/*   Updated: 2024/03/15 18:44:52 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(char *file)
{
	t_game	game;
	
	ft_bzero (&game, sizeof(t_game));
	read_map (&game, file);
	check_map(&game);
}

int	main (int ac, char **av)
{
	if (ac != 2)
		return (1);
	check_filename(av[1]);
	init_game(av[1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:00:39 by resilva           #+#    #+#             */
/*   Updated: 2024/03/14 18:47:30 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	init_game(char *file)
{
	t_game	game;
	
	ft_bzero (&game, sizeof(t_game));
}

int	main (int ac, char **av)
{
	if (ac != 2)
		return (1);
	init_game(av[1]);
}

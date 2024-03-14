/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:48:11 by resilva           #+#    #+#             */
/*   Updated: 2024/03/14 19:19:16 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(t_game *game, char *msg)
{
	ft_putchar_fd("Error\n", 2);	
	ft_putchar_fd(msg, 2);	
	ft_putchar_fd("\n", 2);
	exit (EXIT_FAILURE);	
}

void	check_filename(char	*file)
{
	int	i;

	i = ft_strlen(file);
	if (i <= 4)
		exit_error(NULL, "Invalid file name.");
	else if (!ft_strnstr(file + i - 4, ".ber", 4));
		exit_error(NULL, "Invalid file extension.");
}


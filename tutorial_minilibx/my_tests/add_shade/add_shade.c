/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:07:14 by resilva           #+#    #+#             */
/*   Updated: 2024/03/22 19:43:38 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	add_shade(int color, double distance)
{
	int	r = (color >> 16) & 0xFF;
	int	g = (color >> 8) & 0xFF;
	int	b = color & 0xFF;

	r = r * (1 - distance);
	g = g * (1 - distance);
	b = b * (1 - distance);

	return (r << 16) | (g << 8) | b;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("You need to use: %s 'shading number'\n"
		"For example: '%s 0.5' (for a shading of 0.5)\n", av[0], av[0]);
		return (1);
	}
	int		color = 0xFFAABB;
	double	distance = strtod(av[1], NULL);

	int		shade_color = add_shade(color, distance);

	printf("Current color: 0x%06X\n", color);
	printf("Shading: %.2f\n", distance);
	printf("Shade color: 0x%06X\n", shade_color);
	return (0);
}

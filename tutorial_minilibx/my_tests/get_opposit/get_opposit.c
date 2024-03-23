/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opposit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:21:40 by resilva           #+#    #+#             */
/*   Updated: 2024/03/22 19:45:03 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	get_opposit(int color)
{
	int	r = 255 - ((color >> 16) & 0xFF);
	int	g = 255 - ((color >> 8) & 0xFF);
	int	b = 255 - (color & 0xFF);

	return (r << 16 | (g << 8) | b);
}

int	main(void)
{
	int	color = 0xFFAABB;

	int	opposit_color = get_opposit(color);

	printf("Current color: %06X\n", color);
	printf("Opposit color: %06X\n", opposit_color);
}

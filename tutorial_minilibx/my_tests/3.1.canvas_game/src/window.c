/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:29:28 by resilva           #+#    #+#             */
/*   Updated: 2024/02/19 18:35:56 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../include/window_and_images.h"
#include <stdio.h>
#include <stdlib.h>

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int cor)
{
	char	*dst;
	
	if (x >= 0 && y >= 00 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *)dst = cor;
	}
}

int	exit_prog(t_win *window)
{
	if (window)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit (EXIT_SUCCESS);
}

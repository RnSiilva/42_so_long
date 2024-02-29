/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:46:45 by resilva           #+#    #+#             */
/*   Updated: 2024/02/22 20:13:54 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include "../include/window_and_images.h"



void	draw_square(t_square square, t_img img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while(i < square.size && i + square.y < img.h)
	{
		j = 0;
		while (j < square.size && j + square.x < img.w)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_win	prog;
	t_img	image;

	prog = new_program(300, 300, "Canvas_Game");
	if (!prog.mlx_ptr || !prog.win_ptr)
		return (1);
	image = new_img(300, 300, prog);
	{
		/* DRAW A GIGANT GREEN SQUARE 300X300*/
		draw_square((t_square){0, 0, 300, 0x00FFFFFF}, image);
		mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
		//mlx_destroy_image(prog.mlx_ptr, image.img_ptr);
	}
	/*HOOK*/
	mlx_key_hook(prog.win_ptr, read_keys, &prog);
	mlx_hook(prog.win_ptr, 2, 0, continous_read_keys, &image);
	mlx_mouse_hook(prog.win_ptr, read_mouse, &image);
	mlx_hook(prog.win_ptr, 6, 0, follow_mouse, &image);
	mlx_hook(prog.win_ptr, 17, 0, exit_prog, &prog);
	mlx_loop(prog.mlx_ptr);
	return (0);
}

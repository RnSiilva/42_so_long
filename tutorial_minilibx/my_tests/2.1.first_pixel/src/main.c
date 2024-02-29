/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:46:45 by resilva           #+#    #+#             */
/*   Updated: 2024/02/17 15:20:31 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include "../include/window_and_images.h"

int	main(void)
{
	t_win	prog;
	t_img	image;

	prog = new_program(300, 300, "First_Px");
	if (!prog.mlx_ptr || !prog.win_ptr)
		return (1);
	{
		/*
		t_img	image_4x4;
		
		image_4x4.win = prog;
		image_4x4.img_ptr = mlx_new_image(prog.mlx_ptr, 4, 4);
		image_4x4.addr = mlx_get_data_addr(image_4x4.img_ptr, &(image_4x4.bpp), &(image_4x4.line_len), &(image_4x4.endian));
		image_4x4.w = 4;
		image_4x4.h = 4;
		memcpy(image_4x4.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);
		mlx_put_image_to_window(image_4x4.win.mlx_ptr, image_4x4.win.win_ptr, image_4x4.img_ptr, 10, 10);
		
		printf("Let's find out what's inside our structure :D\n\n");
		printf("img_ptr		: [%p]\n", image_4x4.img_ptr);		
		printf("bpp		: [%d]\n", image_4x4.bpp);
		printf("line_len	: [%d]\n", image_4x4.line_len);
		printf("endian		: [%d]\n", image_4x4.endian);
		printf("addr		: [%p]\n", image_4x4.addr);
		*/

		image = new_img(300, 300, prog);
		memcpy(image.addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);
		mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 10, 10);
		mlx_destroy_image(prog.mlx_ptr, image.img_ptr);
	}
	mlx_loop(prog.mlx_ptr);
	return (0);
}

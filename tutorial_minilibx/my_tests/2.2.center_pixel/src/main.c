/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:46:45 by resilva           #+#    #+#             */
/*   Updated: 2024/02/19 18:36:57 by resilva          ###   ########.fr       */
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

	prog = new_program(300, 300, "Center_Px");
	if (!prog.mlx_ptr || !prog.win_ptr)
		return (1);

	/*COULD INSTEAD OF HAVING ALL THE WORK BELOW, SIMPLY USE
	THE FOLLOWING MLX FUNCTION:
	
	mlx_pixel_put(prog.mlx_ptr, prog.win_ptr, 150, 150, 0x00FFFFFF);
	
	BUT THIS IS A VERY SLOW PROCESS, SO WE WILL DO IT AS BELOW.*/
	image = new_img(300, 300, prog);
	{
		/* PUT WHITE PIXEL IN THE CENTER*/
		put_pixel_img(image, 150, 150, 0x00FFFFFF);
		mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
		mlx_destroy_image(prog.mlx_ptr, image.img_ptr);
	}
	mlx_hook(prog.win_ptr, 17, 0, exit_prog, &prog);
	mlx_loop(prog.mlx_ptr);
	return (0);
}

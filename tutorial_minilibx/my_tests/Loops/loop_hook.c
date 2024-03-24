/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:49:28 by resilva           #+#    #+#             */
/*   Updated: 2024/03/24 02:58:31 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_hook.h"

void	put_pixel_img(t_img *img, int color)
{
	int	x = WIDTH;
	int	y = HEIGTH;
	char	*dst;

	while (y--)
	{
		x = WIDTH;
		while (x--)
		{
			dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
			*(unsigned int *)dst = color;
		}
	}	
}

int	render_next_frame(t_win *win)
{
	static int	color = BLUE;
	
	if (color == RED)
	{
		put_pixel_img(win->img, GREEN);
		color = GREEN;
	}
	else if (color == GREEN)
	{
		put_pixel_img(win->img, BLUE);
		color = BLUE;
	}
	else
	{
		put_pixel_img(win->img, RED);
		color = RED;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img, 0, 0);
	usleep(1000000);
	return (0);
}

int	destroy(t_win *win)
{
	mlx_destroy_display(win->mlx_ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	exit (EXIT_SUCCESS);
	return (0);
}

int	key_press(int keycode, t_win *win)
{
	if (keycode == ESC)
	{
		mlx_destroy_display(win->mlx_ptr);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit (EXIT_SUCCESS);
		return (0);
	}
	return (0);
}

int	main(void)
{
	t_win	win;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, WIDTH, HEIGTH, "Rainbow Renderer");

	win.img->img = mlx_new_image(win.mlx_ptr, WIDTH, HEIGTH);
	win.img->addr = mlx_get_data_addr(win.img->img, &win.img->bpp, &win.img->line_len, &win.img->end);

	mlx_loop_hook(win.mlx_ptr, render_next_frame, &win);
	mlx_hook(win.win_ptr, ON_DESTROY, 0, destroy, &win);
	mlx_key_hook(win.win_ptr, key_press, &win);
	mlx_loop(win.mlx_ptr);
}

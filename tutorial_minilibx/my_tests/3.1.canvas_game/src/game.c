#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/window_and_images.h"

int	follow = 0;
int	size = 10;

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

int	get_color(void)
{
	return (rand() % 2147483647);
}

int	read_keys(int key_pressed, t_win *param)
{
	if (key_pressed == ESC)
	{
		printf("The %d key (ESC) has been pressed\n\n", key_pressed);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_display(param->mlx_ptr);
		free(param->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", key_pressed);
	return (0);
}

int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	t_square	s;
	t_img		*img;
	int			x;
	int			y;

	img = (t_img *)param;
	if (!img)
		return (-1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, get_color()};
	draw_square(s, *img);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	(void)button;
	return (0);
}

int	continous_read_keys(int key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (!img)
		exit_prog(&img->win);
	else if (key_pressed == UP)
	{
		if (size > 1)
			size--;
	}
	else if (key_pressed == RAND_COLOR)
		get_color();
	return (0);
}

int	follow_mouse(int mouse_x, int mouse_y, void *param)
{
	t_square	s;
	t_img		*img;
	int			x;
	int			y;

	img = (t_img *)param;
	if (!img)
		return (1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	if (!follow)
		return (3);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, get_color()};
	draw_square(s, *img);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	return (0);
}


#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/window_and_images.h"

int	follow = 0;
int	size = 10;

int	get_color(void)
{
	return (rand() % 2147483647);
}

int	read_keys(int key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (key_pressed == XK_Escape || !img)
		exit_prog(&img->win);
	else if (key_pressed == XK_KP_Enter)
		draw_square((t_square){0, 0, img->w, 0xFFFFFF}, *img);
	else if (key_pressed == XK_f)
		follow = !follow;
	else if (key_pressed == XK_c)
		get_color();
	//else if (key_pressed == PENGUIN)
	//	penguin(*img);
	else
		return (-1);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	return (0);
}

int	continous_read_keys(int key_pressed, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (!img)
		exit_prog(&img->win);
	else if (key_pressed == XK_Up)
	{
		if (size < img->w / 4)
			size++;
	}
	else if (key_pressed == XK_Down)
	{
		if (size > 1)
			size--;
	}
	else if (key_pressed == RAND_COLOR)
		get_color();
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
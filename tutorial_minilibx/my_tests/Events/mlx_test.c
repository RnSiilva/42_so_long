/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:31:50 by resilva           #+#    #+#             */
/*   Updated: 2024/03/23 22:17:56 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_test.h"

int	key_pressed(int keycode, t_win *win)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_display(win->mlx_ptr);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	destroy(t_win *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	exit (EXIT_SUCCESS);
}

int	resize(int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	(void)win;
	
	printf("Window resized\n");
	return (0);
}

int	mouse_enter(int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	(void)win;

	return (printf("Hello!\n"));
}

int	mouse_leave(int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	(void)win;

	return (printf("Bye!\n"));
}

int	main(void)
{
	t_win	win;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, WIDTH, HEIGTH, "Hook Events");
	mlx_hook(win.win_ptr, ON_KEYDOWN, 1L<<0, key_pressed, &win);
	mlx_hook(win.win_ptr, ON_DESTROY, 0, destroy, &win);
	mlx_hook(win.win_ptr, ON_MOUSE_ENTER, 1L<<4, mouse_enter, &win);
	mlx_hook(win.win_ptr, ON_MOUSE_LEAVE, 1L<<5, mouse_leave, &win);
	mlx_hook(win.win_ptr, ON_RESIZE, 1L<<18, resize, &win);
	mlx_loop(win.mlx_ptr);
}

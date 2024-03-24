/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:21:00 by resilva           #+#    #+#             */
/*   Updated: 2024/03/24 00:02:06 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook.h"

int	destroy(t_win *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	exit (EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_win *win)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_display(win->mlx_ptr);
		exit (EXIT_SUCCESS);
	}
	printf("Keycode %d has been pressed\n", keycode);
	return (0);
}

int	mouse_move(int key_mouse, int x, int y, t_win *win)
{
	(void)win;
	if (key_mouse >= 1 && key_mouse <= 5)
		printf("Key_mouse -> %d; x -> %d; y -> %d\n", key_mouse, x, y);
	else
		printf("x -> %d; y -> %d\n", key_mouse, x);
	return (0);
}

int	main(void)
{
	t_win	win;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 800, 600, "Event Hook");
	mlx_hook(win.win_ptr, ON_DESTROY, 0, destroy, &win);
	mlx_key_hook(win.win_ptr, key_hook, &win);
	mlx_hook(win.win_ptr, ON_MOUSEMOVE, 1L<<6, mouse_move, &win);
	mlx_mouse_hook(win.win_ptr, mouse_move, &win);
	mlx_loop(win.mlx_ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_esc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:31:50 by resilva           #+#    #+#             */
/*   Updated: 2024/03/23 17:01:11 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGTH 600

typedef enum	e_keys
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_RESIZE = 8,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ESC = 65307
}				t_keys;

typedef struct	s_win
{
	void	*win_ptr;
	void	*mlx_ptr;
}				t_win;

int	close(int keycode, t_win *win)
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
	
	printf("Window resized to %d x %d", x, y);
	return (0);
}

int	main(void)
{
	t_win	win;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, WIDTH, HEIGTH, "hook");
	mlx_hook(win.win_ptr, ON_KEYDOWN, 1L<<0, close, &win);
	mlx_hook(win.win_ptr, ON_RESIZE, 1L<<0, resize, &win);
	mlx_hook(win.win_ptr, ON_DESTROY, 0, destroy, &win);
	mlx_loop(win.mlx_ptr);
}

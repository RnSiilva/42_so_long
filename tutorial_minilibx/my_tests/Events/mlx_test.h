/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:12:54 by resilva           #+#    #+#             */
/*   Updated: 2024/03/23 22:04:23 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 800
#define HEIGTH 600

typedef enum	e_keys
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_MOUSE_ENTER = 7,
	ON_MOUSE_LEAVE = 8,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_RESIZE = 22,
	ESC = 65307
}				t_keys;

typedef struct	s_win
{
	void	*win_ptr;
	void	*mlx_ptr;
	clock_t	key_press_time;
}				t_win;


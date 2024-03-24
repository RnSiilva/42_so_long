/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:49:38 by resilva           #+#    #+#             */
/*   Updated: 2024/03/24 02:55:42 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 800
#define HEIGTH 600
#define	RED 0xFF0000
#define	GREEN 0x00FF00
#define	BLUE 0x0000FF

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		end;
}				t_img;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
}				t_win;

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
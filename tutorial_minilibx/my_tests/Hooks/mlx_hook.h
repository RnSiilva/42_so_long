/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:21:14 by resilva           #+#    #+#             */
/*   Updated: 2024/03/23 23:46:20 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
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
	ESC = 65307,
	
}				t_keys;


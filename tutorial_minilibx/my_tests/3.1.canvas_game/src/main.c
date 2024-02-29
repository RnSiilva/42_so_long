/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:46:45 by resilva           #+#    #+#             */
/*   Updated: 2024/02/22 18:53:11 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include "../include/window_and_images.h"

int	main(void)
{
	t_win	prog;

	prog = new_program(300, 300, "Canvas_Game");
	prog.win_ptr = mlx_new_window(prog.mlx_ptr, 300, 300, "Canvas_game");

	/*HOOK*/
	mlx_key_hook(prog.win_ptr, read_keys, &prog);
	//mlx_hook(prog.win_ptr, 2, 0, continous_read_keys, &prog);
	//mlx_mouse_hook(prog.win_ptr, read_mouse, &prog);
	//mlx_hook(prog.win_ptr, 6, 0, follow_mouse, &prog);
	//mlx_hook(prog.win_ptr, 17, 0, exit_prog, &prog);
	mlx_loop(prog.mlx_ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:46:45 by resilva           #+#    #+#             */
/*   Updated: 2024/02/16 20:52:36 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../include/window.h"

int	main(void)
{
	/*
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "BlackWind");
	if (!win_ptr)
		return (2);
	mlx_loop(mlx_ptr);
	return (0);
	*/

	t_win	prog;

	prog = new_program(300, 300, "BlackWind");
	if (!prog.mlx_ptr || !prog.win_ptr)
		return (1);
	mlx_loop(prog.mlx_ptr);
	return (0);
}
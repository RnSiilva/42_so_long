/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_images.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:21:00 by resilva           #+#    #+#             */
/*   Updated: 2024/02/16 20:49:16 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}				t_win;

typedef struct	s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

t_win	new_program(int w, int h, char *str);

#endif

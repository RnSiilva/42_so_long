/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_images.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:21:00 by resilva           #+#    #+#             */
/*   Updated: 2024/02/22 17:38:42 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>
# include <stdlib.h>

# define ESC 9
# define ENTER 36
# define FOLLOW 41
# define COLOR 54
# define UP 111
# define DOWN 116
# define PENGUIN 96
# define RAND_COLOR 27

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

typedef struct	square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}				t_square;

t_win	new_program(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_img img, int x, int y, int cor);
int		exit_prog(t_win *window);
void	draw_square(t_square square, t_img img);
int		read_keys(int key_pressed, void *param);
int		read_mouse(int button, int mouse_x, int mouse_y, void *param);
int		continous_read_keys(int key_pressed, void *param);
int	follow_mouse(int mouse_x, int mouse_y, void *param);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:17:12 by tshevchu          #+#    #+#             */
/*   Updated: 2017/10/24 16:19:05 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/include/libft.h"
# include <mlx.h>
# include <pthread.h>

# define BLACK 0
# define COLORFUL 1

typedef struct	s_fract
{
	int			depth;
	char		*dep;
	double		julc_im;
	double		julc_r;
	double		move_x;
	double		move_y;
	double		zoom;
	int			jul_shape;
}				t_fract;

typedef struct	s_draw
{
	void		*mlx;
	void		*win;
	void		*img_w;
	char		*img;
	int			error;
	int			fractal;
	int			bpp;
	int			size_l;
	int			en;
	int			w;
	int			h;
	int			color;
}				t_draw;

typedef struct	s_all
{
	t_draw		*draw;
	t_fract		*fract;
}				t_all;

t_all			*init_all(void);
void			start_threads(t_all *all);
void			do_julia(t_all *all, int i, int j);
void			do_mandelbrot(t_all *all, int i, int j);
void			do_burning_ship(t_all *all, int i, int j);
void			*thread_first(void *data);
void			*thread_second(void *data);
void			*thread_third(void *data);
void			*thread_fourth(void *data);
void			*thread_fifth(void *data);
void			show_keys(t_all *all);
void			my_putpixel(t_all *all, int n, int i, int j);
void			my_putpixel_black(t_all *all, int n, int i, int j);
int				key_processing(int keycode, t_all *all);
int				mouse_processing(int button, int x, int y, t_all *all);
int				shape_julia(int x, int y, t_all *all);
void			clean_all(t_all *all);

#endif

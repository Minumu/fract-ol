/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:12:54 by tshevchu          #+#    #+#             */
/*   Updated: 2017/10/24 16:15:38 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_burning_ship(t_all *all, int i, int j)
{
	double	c_z_re_im[4];
	double	old_z;
	int		n;

	c_z_re_im[0] = 2 * (i - all->draw->w / 2) / (0.5 * all->draw->w *
			all->fract->zoom) - (all->fract->move_x);
	c_z_re_im[1] = 2 * (j - all->draw->h / 2) / (0.5 * all->draw->h *
			all->fract->zoom) - all->fract->move_y;
	c_z_re_im[2] = 0.0;
	c_z_re_im[3] = 0.0;
	n = 0;
	while (n < all->fract->depth && c_z_re_im[2] * c_z_re_im[2] +
									c_z_re_im[3] * c_z_re_im[3] < 4)
	{
		old_z = c_z_re_im[2] * c_z_re_im[2] - c_z_re_im[3] * c_z_re_im[3];
		c_z_re_im[3] = fabs(2 * c_z_re_im[2] * c_z_re_im[3] + c_z_re_im[1]);
		c_z_re_im[2] = fabs(old_z + c_z_re_im[0]);
		n++;
	}
	if (all->draw->color == COLORFUL)
		my_putpixel(all, n, i, j);
	else
		my_putpixel_black(all, n, i, j);
}

void	do_mandelbrot(t_all *all, int i, int j)
{
	double	c_z_re_im[4];
	double	old_z;
	int		n;

	c_z_re_im[0] = 2 * (i - all->draw->w / 2) / (0.5 * all->draw->w *
			all->fract->zoom) - (all->fract->move_x);
	c_z_re_im[1] = 2 * (j - all->draw->h / 2) / (0.5 * all->draw->h *
			all->fract->zoom) - all->fract->move_y;
	c_z_re_im[2] = 0.0;
	c_z_re_im[3] = 0.0;
	n = 0;
	while (n < all->fract->depth && c_z_re_im[2] * c_z_re_im[2] +
									c_z_re_im[3] * c_z_re_im[3] < 4)
	{
		old_z = c_z_re_im[2] * c_z_re_im[2] - c_z_re_im[3] * c_z_re_im[3];
		c_z_re_im[3] = 2 * c_z_re_im[2] * c_z_re_im[3] + c_z_re_im[1];
		c_z_re_im[2] = old_z + c_z_re_im[0];
		n++;
	}
	if (all->draw->color == COLORFUL)
		my_putpixel(all, n, i, j);
	else
		my_putpixel_black(all, n, i, j);
}

void	do_julia(t_all *all, int i, int j)
{
	double	z_r;
	double	z_im;
	double	old_z;
	int		n;

	z_r = 2 * (i - all->draw->w / 2) / (0.5 * all->draw->w *
			all->fract->zoom) - all->fract->move_x;
	z_im = 2 * (j - all->draw->h / 2) / (0.5 * all->draw->h *
			all->fract->zoom) - all->fract->move_y;
	n = 0;
	while (n < all->fract->depth && z_r * z_r + z_im * z_im < 4)
	{
		old_z = z_r * z_r - z_im * z_im;
		z_im = 2 * z_r * z_im + all->fract->julc_im;
		z_r = old_z + all->fract->julc_r;
		n++;
	}
	if (all->draw->color == COLORFUL)
		my_putpixel(all, n, i, j);
	else
		my_putpixel_black(all, n, i, j);
}

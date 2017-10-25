/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel_black.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:24:08 by tshevchu          #+#    #+#             */
/*   Updated: 2017/10/24 16:27:50 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	putpixel_black_case3(t_all *all, int n, int i, int j)
{
	if (n > 100 && n < all->fract->depth)
	{
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8))) =
			(char)((150 - ((255 - 1.5 * all->fract->depth) /
			(1 - (double)(all->fract->depth) / 100))) / 100 *
			n + ((255 - 1.5 * all->fract->depth) /
			(1 - (double)(all->fract->depth) / 100)));
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 1) =
			(char)((150 - ((255 - 1.5 * all->fract->depth) /
			(1 - (double)(all->fract->depth) / 100))) / 100 *
			n + ((255 - 1.5 * all->fract->depth) /
			(1 - (double)(all->fract->depth) / 100)));
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 2) =
			(char)((150 - ((255 - 1.5 * all->fract->depth) /
			(1 - (double)(all->fract->depth) / 100))) / 100 *
			n + ((255 - 1.5 * all->fract->depth) /
			(1 - (double)(all->fract->depth) / 100)));
	}
}

void	putpixel_black_case2(t_all *all, int n, int i, int j)
{
	if (n > 10 && n <= 20)
	{
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8))) = (char)(10 * n);
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 1) = (char)(10 * n);
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 2) = (char)(10 * n);
	}
	else if (n > 20 && n <= 100)
	{
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8))) = (char)(-0.625 * n + 212.5);
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 1) = (char)(-0.625 * n + 212.5);
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 2) = (char)(-0.625 * n + 212.5);
	}
	else
		putpixel_black_case3(all, n, i, j);
}

void	my_putpixel_black(t_all *all, int n, int i, int j)
{
	if (n == all->fract->depth)
	{
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8))) = (char)(230);
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 1) = (char)(230);
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 2) = (char)(230);
	}
	else if (n <= 10)
	{
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8))) = (char)(10 * n);
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 1) = (char)(10 * n);
		*(all->draw->img + (j * all->draw->size_l + i *
			(all->draw->bpp / 8)) + 2) = (char)(10 * n);
	}
	else
		putpixel_black_case2(all, n, i, j);
}

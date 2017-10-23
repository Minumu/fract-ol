#include "fractol.h"

void	my_putpixel(t_all *all, int n, int i ,int j)
{
	if (n == all->fract->depth)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(220);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(255);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(255);
	}
	else if (n == 0)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(0);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(0);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(2.333 * n + 188.667);
	}
	else if (n <= 10)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(0);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(9 * n - 9);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(2.333 * n + 188.667);
	}
	else if (n > 10 && n <= 20)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(0);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(11 * n - 40);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(4.667 * n + 160.6667);
	}
	else if (n > 20 && n <= 100)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(1.7722 * n - 37.2151);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(0.3671 * n + 172.2912);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(254);
	}
	else if (n > 100 && n < all->fract->depth)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)((140 - ((188 - 1.4 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100))) / 100 *
				n + ((188 - 1.4 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100)));
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)((209 - ((251 - 2.09 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100))) / 100 *
					   n + ((251 - 2.09 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100)));
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(254);
	}
}


void	my_putpixel_black(t_all *all, int n, int i, int j)
{
	if (n == all->fract->depth)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(230);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(230);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(230);
	}
	else if (n <= 10)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(10 * n);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(10 * n);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(10 * n);
	}
	else if (n > 10 && n <= 20)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(10 * n);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(10 * n);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(10 * n);
	}
	else if (n > 20 && n <= 100)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(-0.625 * n + 212.5);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(-0.625 * n + 212.5);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(-0.625 * n + 212.5);
	}
	else if (n > 100 && n < all->fract->depth)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)((150 - ((255 - 1.5 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100))) / 100 *
					   n + ((255 - 1.5 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100)));
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)((150 - ((255 - 1.5 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100))) / 100 *
					   n + ((255 - 1.5 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100)));
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)((150 - ((255 - 1.5 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100))) / 100 *
					   n + ((255 - 1.5 * all->fract->depth) / (1 - (double)(all->fract->depth) / 100)));
	}
}
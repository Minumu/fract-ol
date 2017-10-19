#include "fractol.h"

void	my_putpixel(t_all *all, int n, int i, int j)
{
	if (n == all->fract->depth)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
		(char)(0);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
		(char)(0);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
		(char)(0);
	}
	else
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(sinf((float)n / all->fract->depth) * 255);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(sinf((float)n / all->fract->depth) * 230);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(sinf((float)n / all->fract->depth) * 214);
	}
}
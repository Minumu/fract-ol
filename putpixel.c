#include "fractol.h"

void	my_putpixel(t_all *all, int n, int i, int j)
{
	if (n == all->fract->depth)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) = (char)(230);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) = (char)(230);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) = (char)(230);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
//				(char)(220);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
//				(char)(255);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
//				(char)(255);
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
		else if (n > 100 && n < 500)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(0.2625 * n + 123.75);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(0.2625 * n + 123.75);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(0.2625 * n + 123.75);
	}
//	else if (n <= 10)
//	{
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
//				(char)(0);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
//				(char)(9 * n - 9);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
//				(char)(2.333 * n + 188.667);
//	}
//	else if (n > 10 && n <= 20)
//	{
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
//				(char)(0);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
//				(char)(11 * n - 40);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
//				(char)(4.667 * n + 160.6667);
//	}
//	else if (n > 20 && n <= 100)
//	{
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
//				(char)(1.7722 * n - 37.2151);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
//				(char)(0.3671 * n + 172.2912);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
//				(char)(254);
//	}
//	else if (n > 100 && n < 500)
//	{
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
//				(char)(0.1203 * n + 127.8496);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
//				(char)(0.1053 * n + 198.3684);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
//				(char)(254);
//	}
//	else if (n > 200 && n < 500)
//	{
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
//				(char)(151);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
//				(char)(-0.285 * n + 277);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
//				(char)(254);
//	}
//	else if (n > 400 && n < 500)
//	{
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
//				(char)(175);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
//				(char)(-0.5 * n + 440);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
//				(char)(254);
//	}
//	else
//	{
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
//				(char)(sin((double)n / all->fract->depth) * 255);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
//				(char)(sin((double)n / all->fract->depth) * 230);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
//				(char)(sin((double)n / all->fract->depth) * 214);
//	}
/*
	if (n < 20)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(255);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(0);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(0);
	}
	else if (n >= 20 && n < all->fract->depth / 5)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)((0.00625 * (double)n + 0.375) * 239);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)((0.00625 * (double)n + 0.375) * 170);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)((0.00625 * (double)n + 0.375) * 50);
	}
	else if (n == all->fract->depth)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
		(char)(0);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
		(char)(0);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
		(char)(0);
	}
	else if (n >= all->fract->depth / 5 )
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(sin((double)n / all->fract->depth) * 200);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(sin((double)n / all->fract->depth) * 150);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(sin((double)n / all->fract->depth) * 180);
		check_black(all, n, i, j);
	}
	else //if (n >= all->fract->depth / 2 && n <= all->fract->depth / 2)
	{
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
				(char)(sin((double)n / all->fract->depth) * 190);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
				(char)(sin((double)n / all->fract->depth) * 23);
		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
				(char)(sin((double)n / all->fract->depth) * 250);
		check_black(all, n, i, j);
	}*/
//	else
//	{
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8))) =
//				(char)(sin((double)n / all->fract->depth) * 255);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 1) =
//				(char)(sin((double)n / all->fract->depth) * 230);
//		*(all->draw->img + (j * all->draw->size_l + i * (all->draw->bpp / 8)) + 2) =
//				(char)(sin((double)n / all->fract->depth) * 214);
//	}
}
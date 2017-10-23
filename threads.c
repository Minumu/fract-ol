#include "fractol.h"

void	*thread_first(void *data)
{
	t_all *all;
	int i;
	int j;

	all = (t_all*)data;
	i = 0;
	while (i < all->draw->w / 2)
	{
		j = 0;
		while (j < all->draw->h / 4)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			else if (all->draw->fractal == 2)
				do_julia(all, i, j);
			else if (all->draw->fractal == 3)
				do_burning_ship(all, i, j);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void	*thread_second(void *data)
{
	t_all *all;
	int j;
	int i;

	all = (t_all*)data;
	i = 0;
	while (i < all->draw->w / 2)
	{
		j = all->draw->h / 4;
		while (j < all->draw->h / 2)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			else if (all->draw->fractal == 2)
				do_julia(all, i, j);
			else if (all->draw->fractal == 3)
				do_burning_ship(all, i, j);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void	*thread_third(void *data)
{
	t_all *all;
	int j;
	int i;

	all = (t_all*)data;
	i = 0;
	while (i < all->draw->w / 2)
	{
		j = all->draw->h / 2;
		while (j < 3 * all->draw->h / 4)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			else if (all->draw->fractal == 2)
				do_julia(all, i, j);
			else if (all->draw->fractal == 3)
				do_burning_ship(all, i, j);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void	*thread_fourth(void *data)
{
	t_all *all;
	int j;
	int i;

	all = (t_all*)data;
	i = 0;
	while (i < all->draw->w / 2)
	{
		j = 3 * all->draw->h / 4;
		while (j < all->draw->h)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			else if (all->draw->fractal == 2)
				do_julia(all, i, j);
			else if (all->draw->fractal == 3)
				do_burning_ship(all, i, j);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void	*thread_fifth(void *data)
{
	t_all *all;
	int i;
	int j;

	all = (t_all*)data;
	i = all->draw->w / 2;
	while (i < all->draw->w)
	{
		j = 0;
		while (j < all->draw->h / 4)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			else if (all->draw->fractal == 2)
				do_julia(all, i, j);
			else if (all->draw->fractal == 3)
				do_burning_ship(all, i, j);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void	*thread_sixth(void *data)
{
	t_all *all;
	int j;
	int i;

	all = (t_all*)data;
	i = all->draw->w / 2;
	while (i < all->draw->w)
	{
		j = all->draw->h / 4;
		while (j < all->draw->h / 2)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			else if (all->draw->fractal == 2)
				do_julia(all, i, j);
			else if (all->draw->fractal == 3)
				do_burning_ship(all, i, j);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void	*thread_seventh(void *data)
{
	t_all *all;
	int j;
	int i;

	all = (t_all*)data;
	i = all->draw->w / 2;
	while (i < all->draw->w)
	{
		j = all->draw->h / 2;
		while (j < 3 * all->draw->h / 4)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			else if (all->draw->fractal == 2)
				do_julia(all, i, j);
			else if (all->draw->fractal == 3)
				do_burning_ship(all, i, j);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}

void	*thread_eighth(void *data)
{
	t_all *all;
	int j;
	int i;

	all = (t_all*)data;
	i = all->draw->w / 2;
	while (i < all->draw->w)
	{
		j = 3 * all->draw->h / 4;
		while (j < all->draw->h)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			else if (all->draw->fractal == 2)
				do_julia(all, i, j);
			else if (all->draw->fractal == 3)
				do_burning_ship(all, i, j);
			j++;
		}
		i++;
	}
	pthread_exit(NULL);
}


void	start_threads(t_all *all)
{
	pthread_t thread[8];
	int i;
	char str[20];

	pthread_create(&thread[0], NULL, &thread_first, all);
	pthread_create(&thread[1], NULL, &thread_second, all);
	pthread_create(&thread[2], NULL, &thread_third, all);
	pthread_create(&thread[3], NULL, &thread_fourth, all);
	pthread_create(&thread[4], NULL, &thread_fifth, all);
	pthread_create(&thread[5], NULL, &thread_sixth, all);
	pthread_create(&thread[6], NULL, &thread_seventh, all);
	pthread_create(&thread[7], NULL, &thread_eighth, all);
	i = 0;
	while (i < 8)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(all->draw->mlx, all->draw->win,
							all->draw->img_w, 0, 0);
	mlx_mouse_hook(all->draw->win, mouse_processing, all);
	mlx_hook(all->draw->win, 2, 5, key_processing, all);
	if (all->draw->fractal == 2)
	{
		mlx_hook(all->draw->win, 6, 0, shape_julia, all);
		gcvt(all->fract->julc_im, 4, str);
		mlx_string_put(all->draw->mlx, all->draw->win, 7, 50, 0xffffff, "c_image:");
		mlx_string_put(all->draw->mlx, all->draw->win, 90, 50, 0xffffff, str);
		gcvt(all->fract->julc_r, 4, str);
		mlx_string_put(all->draw->mlx, all->draw->win, 7, 85, 0xffffff, "c_real:");
		mlx_string_put(all->draw->mlx, all->draw->win, 80, 85, 0xffffff, str);

	}
	mlx_string_put(all->draw->mlx, all->draw->win, 7, 15, 0xffffff, "depth:");
	mlx_string_put(all->draw->mlx, all->draw->win, 70, 15, 0xffffff, ft_itoa(all->fract->depth));
	mlx_loop(all->draw->mlx);
}

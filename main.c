#include "fractol.h"

void	check_fractal(t_all *all, char **av)
{
	if (av[1][0] == '1')
		all->draw->fractal = 1;
	else if (av[1][0] == '2')
		all->draw->fractal = 2;
	else
		return ;

}

void	do_fractal(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (i < all->draw->w)
	{
		j = 0;
		while (j < all->draw->h)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			if (all->draw->fractal == 2)
				do_julia(all, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(all->draw->mlx, all->draw->win,
							all->draw->img_w, 0, 0);
}

void	do_mandelbrot(t_all *all, int i, int j)
{
	double z_r;
	double z_im;
	double old_z;

//	all->fract->c_r = all->lim->xmin + i * all->fract->pixw + all->fract->zoom;
//	all->fract->c_im = all->lim->ymin + j * all->fract->pixh + all->fract->zoom;
	all->fract->c_r = 1.5 * (i - all->draw->w / 2) / (0.5 * all->draw->w *
			all->fract->zoom) - all->fract->move_x;
	all->fract->c_im = (j - all->draw->h / 2) / (0.5 * all->draw->h *
			all->fract->zoom) - all->fract->move_y;
	z_r = 0.0;
	z_im = 0.0;
	int n = 0;
	while (n < all->fract->depth && z_r * z_r + z_im * z_im < 4)
	{
		old_z = z_r * z_r - z_im * z_im;
		z_im = 2 * z_r * z_im + all->fract->c_im;
		z_r = old_z + all->fract->c_r;
		n++;
	}
	my_putpixel(all, n, i, j);
}

void	do_julia(t_all *all, int i, int j)
{
	double z_r;
	double z_im;
	double old_z;

//	z_r = all->lim->xmin + i * all->fract->pixw;
//	z_im = all->lim->ymin + j * all->fract->pixh;
	z_r = 1.5 * (i - all->draw->w / 2) / (0.5 * all->draw->w *
			all->fract->zoom) - all->fract->move_x;
	z_im = (j - all->draw->h / 2) / (0.5 * all->draw->h *
			all->fract->zoom) - all->fract->move_y;
	int n = 0;
	while (n < all->fract->depth && z_r * z_r + z_im * z_im < 4)
	{
		old_z = z_r * z_r - z_im * z_im;
		z_im = 2 * z_r * z_im + all->fract->julc_im;
		z_r = old_z + all->fract->julc_r;
		n++;
	}
	my_putpixel(all, n, i, j);
}

int 	main(int ac, char **av)
{
	t_all *all;

	all = init_all();
	if (!av[1])
		return (0);
	all->draw->mlx = mlx_init();
	all->draw->win = mlx_new_window(all->draw->mlx,
							   all->draw->w, all->draw->h, "fractol");
	all->draw->img_w = mlx_new_image(all->draw->mlx, all->draw->w,
								all->draw->h);
	all->draw->img = mlx_get_data_addr(all->draw->img_w, &all->draw->bpp,
								  &all->draw->size_l, &all->draw->en);
	check_fractal(all, av);
	do_fractal(all);
	mlx_mouse_hook(all->draw->win, mouse_processing, all);
	mlx_hook(all->draw->win, 2, 5, key_processing, all);
	mlx_hook(all->draw->win, 6, 0, shape_julia, all);
	mlx_loop(all->draw->mlx);
	return (0);
}
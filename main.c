#include "fractol.h"

void	show_usage(t_all *all)
{
	ft_printf("There are three different types of fractals:\n"
					  "1 - Mandelbrot\n"
					  "2 - Julia\n"
					  "3 - Burning ship\n"
					  "Usage: ./fractol 1\n");
	all->draw->error = 1;
}

void	check_fractal(t_all *all, char **av, int ac)
{
	if (!av[1] || ac > 2)
		show_usage(all);
	if (av[1][0] == '1' && av[1][1] == '\0')
		all->draw->fractal = 1;
	else if (av[1][0] == '2' && av[1][1] == '\0')
		all->draw->fractal = 2;
	else if (av[1][0] == '3' && av[1][1] == '\0')
		all->draw->fractal = 3;
	else
		show_usage(all);
}

/*void	do_fractal1(t_all *all)
{
	int i;
	int j;

	i = 0;
	all->draw->img_w = mlx_new_image(all->draw->mlx, all->draw->w,
									 all->draw->h);
	all->draw->img = mlx_get_data_addr(all->draw->img_w, &all->draw->bpp,
									   &all->draw->size_l, &all->draw->en);
	while (i < all->draw->w)
	{
		j = 0;
		while (j < all->draw->h)
		{
			if (all->draw->fractal == 1)
				do_mandelbrot(all, i, j);
			if (all->draw->fractal == 2)
				do_julia(all, i, j);
			if (all->draw->fractal == 3)
				do_burning_ship(all, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(all->draw->mlx, all->draw->win,
							all->draw->img_w, 0, 0);
	mlx_mouse_hook(all->draw->win, mouse_processing, all);
	mlx_hook(all->draw->win, 2, 5, key_processing, all);
	mlx_hook(all->draw->win, 6, 0, shape_julia, all);
	mlx_loop(all->draw->mlx);
}*/

void	do_burning_ship(t_all *all, int i, int j)
{
	double	z_r;
	double	z_im;
	double	old_z;
	int 	n;
	double c_r;
	double c_im;

//	all->fract->c_r = all->lim->xmin + i * all->fract->pixw + all->fract->zoom;
//	all->fract->c_im = all->lim->ymin + j * all->fract->pixh + all->fract->zoom;
	c_r = 2 * (i - all->draw->w / 2) / (0.5 * all->draw->w *
			all->fract->zoom) - (all->fract->move_x);
	c_im = 2 * (j - all->draw->h / 2) / (0.5 * all->draw->h *
			all->fract->zoom) - all->fract->move_y;
	z_r = 0.0;
	z_im = 0.0;
	n = 0;
	while (n < all->fract->depth && z_r * z_r + z_im * z_im < 4)
	{
		old_z = z_r * z_r - z_im * z_im;
		z_im = fabs(2 * z_r * z_im + c_im);
		z_r = fabs(old_z + c_r);
		n++;
	}
	if (all->draw->color == COLORFUL)
		my_putpixel(all, n, i ,j);
	else
		my_putpixel_black(all, n, i, j);
}
void	do_mandelbrot(t_all *all, int i, int j)
{
	double	z_r;
	double	z_im;
	double	old_z;
	int 	n;
	double c_r;
	double c_im;
//1.375
//	all->fract->c_r = all->lim->xmin + i * all->fract->pixw + all->fract->zoom;
//	all->fract->c_im = all->lim->ymin + j * all->fract->pixh + all->fract->zoom;

	c_r = 2 * (i - all->draw->w / 2) / (0.5 * all->draw->w *
			all->fract->zoom) - (all->fract->move_x);
	c_im = 2 * (j - all->draw->h / 2) / (0.5 * all->draw->h *
			all->fract->zoom) - (all->fract->move_y);
	z_r = 0.0;
	z_im = 0.0;
	n = 0;
	while (n < all->fract->depth && z_r * z_r + z_im * z_im < 4)
	{
		old_z = z_r * z_r - z_im * z_im;
		z_im = 2 * z_r * z_im + c_im;
		z_r = old_z + c_r;
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
	int 	n;
//	z_r = all->lim->xmin + i * all->fract->pixw;
//	z_im = all->lim->ymin + j * all->fract->pixh;
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
		my_putpixel(all, n, i ,j);
	else
		my_putpixel_black(all, n, i, j);
}

int 	main(int ac, char **av)
{
	t_all *all;

	all = init_all();
	check_fractal(all, av, ac);
	if (all->draw->error == 1)
		return (0);
	all->draw->mlx = mlx_init();
	all->draw->win = mlx_new_window(all->draw->mlx,
									all->draw->w, all->draw->h, "fractol");
	all->draw->img_w = mlx_new_image(all->draw->mlx, all->draw->w,
									 all->draw->h);
	all->draw->img = mlx_get_data_addr(all->draw->img_w, &all->draw->bpp,
									   &all->draw->size_l, &all->draw->en);
	start_threads(all);
	return (0);
}
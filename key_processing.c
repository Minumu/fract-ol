#include "fractol.h"

int 	mouse_processing(int button, int x, int y, t_all *all)
{
	ft_printf("button %d  X %d  Y %d\n", button, x, y);
	if (button == 4)
	{
		all->fract->zoom *= 1.5;
		all->fract->move_x -= 1.5 * (x - all->draw->w / 2) / (0.5 * all->draw->w *
															  all->fract->zoom);
		all->fract->move_y -= (y - all->draw->h / 2) / (0.5 * all->draw->h *
														all->fract->zoom);
		printf("mouseX %f  mouseY %f\n", all->fract->move_x, all->fract->move_y);

		do_fractal(all);
	}
	if (button == 5)
	{

		all->fract->move_x += 1.5 * (x - all->draw->w / 2) / (0.5 * all->draw->w *
															   all->fract->zoom);
		all->fract->move_y += (y - all->draw->h / 2) / (0.5 * all->draw->h *
														 all->fract->zoom);
		printf("mouseX %f  mouseY %f\n", all->fract->move_x, all->fract->move_y);
		all->fract->zoom /= 1.5;
		do_fractal(all);
	}
	return (0);
}

int		key_processing(int keycode, t_all *all)
{
	if (keycode == 53)
	{
		mlx_destroy_window(all->draw->mlx, all->draw->win);
		exit(0);
	}
	return (0);
}

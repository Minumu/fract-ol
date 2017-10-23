#include "fractol.h"

int 	shape_julia(int x, int y, t_all *all)
{
	if (all->fract->jul_shape == 1)
	{
		all->fract->julc_im = 2 * (x - all->draw->w / 2) / (0.5 * all->draw->w);
		all->fract->julc_r = 2 * (y - all->draw->h / 2) / (0.5 * all->draw->h);
		start_threads(all);
	}
	return (0);
}

int 	mouse_processing(int button, int x, int y, t_all *all)
{
	if (button == 4)
	{
		all->fract->zoom *= 2;
		all->fract->move_x -= 2 * (x - all->draw->w / 2) / (0.5 * all->draw->w *
				all->fract->zoom);
		all->fract->move_y -= 2 * (y - all->draw->h / 2) / (0.5 * all->draw->h *
				all->fract->zoom);
	}
	else if (button == 5)
	{
		all->fract->move_x += 2 * (x - all->draw->w / 2) / (0.5 * all->draw->w *
				all->fract->zoom);
		all->fract->move_y += 2 * (y - all->draw->h / 2) / (0.5 * all->draw->h *
				all->fract->zoom);
		all->fract->zoom /= 2;
	}
	start_threads(all);
	return (0);
}

int		key_processing(int keycode, t_all *all)
{
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(all->draw->mlx, all->draw->win);
		exit(0);
	}
	else if (keycode == 49)
		all->fract->jul_shape = 1;
	else if (keycode == 36)
		all->fract->jul_shape = 0;
	else if (keycode == 0)
	{
		all->draw->color = BLACK;
		start_threads(all);
	}
	else if (keycode == 1)
	{
		all->draw->color = COLORFUL;
		start_threads(all);
	}
	else if (keycode == 126)
	{
		all->fract->move_y -= 0.1;
		start_threads(all);
	}
	else if (keycode == 125)
	{
		all->fract->move_y += 0.1;
		start_threads(all);
	}
	else if (keycode == 123)
	{
		all->fract->move_x -= 0.1;
		start_threads(all);
	}
	else if (keycode == 124)
	{
		all->fract->move_x += 0.1;
		start_threads(all);
	}
	else if (keycode == 24)
	{
		all->fract->depth += 10;
		start_threads(all);
	}
	else if (keycode == 27)
	{
		all->fract->depth -= 10;
		start_threads(all);
	}
	return (0);
}

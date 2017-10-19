#include "fractol.h"

t_fract			*init_fract(t_draw *draw, t_limits *lim)
{
	t_fract *fract;

	fract = malloc(sizeof(t_fract));
	fract->depth = 500;
	fract->c_im = 0.0;
	fract->c_r = 0.0;
	fract->julc_r = 0.0;
	fract->julc_im = 0.0;
	fract->zoom = 1;
	fract->move_x = 0.0;
	fract->move_y = 0.0;
	fract->pixw = (lim->xmax-lim->xmin)/draw->w;
	fract->pixh = (lim->ymax-lim->ymin)/draw->h;
	return (fract);
}

t_draw			*init_draw(void)
{
	t_draw *draw;

	draw = malloc(sizeof(t_draw));
	draw->mlx = NULL;
	draw->win = NULL;
	draw->img_w = NULL;
	draw->img = NULL;
	draw->fractal = 0;
	draw->w = 600;
	draw->h = 600;
	return (draw);
}

t_limits		*init_limits(void)
{
	t_limits *lim;

	lim = malloc(sizeof(t_limits));
	lim->xmax = 2.0;
	lim->xmin = -2.0;
	lim->ymax = 2.5;
	lim->ymin = -2.5;
	return (lim);
}

t_all			*init_all(void)
{
	t_all *all;

	all = malloc(sizeof(t_all));
	all->draw = init_draw();
	all->lim = init_limits();
	all->fract = init_fract(all->draw, all->lim);
	return (all);
}
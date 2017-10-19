#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "libft/include/libft.h"
# include "minilibx_macos/mlx.h"

# include <stdio.h> // DELETE ////////

typedef struct	s_fract
{
	int			depth;
	double		c_im;
	double		c_r;
	double		julc_im;
	double		julc_r;
	double		pixw;
	double		pixh;
	double 		move_x;
	double		move_y;
	double 		zoom;
}				t_fract;

typedef struct	s_limits
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
}				t_limits;

typedef struct	s_draw
{
	void		*mlx;
	void		*win;
	void		*img_w;
	char		*img;
	int 		fractal;
	int			bpp;
	int			size_l;
	int			en;
	int			w;
	int			h;
}				t_draw;

typedef struct	s_all
{
	t_draw		*draw;
	t_limits	*lim;
	t_fract		*fract;
}				t_all;

t_all			*init_all(void);
void	do_fractal(t_all *all);
void	do_julia(t_all *all, int i, int j);
void	do_mandelbrot(t_all *all, int i, int j);
void	my_putpixel(t_all *all, int n, int i, int j);

int		key_processing(int keycode, t_all *all);
int 	mouse_processing(int button, int x, int y, t_all *all);

#endif

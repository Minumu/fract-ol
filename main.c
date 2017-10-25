/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:22:38 by tshevchu          #+#    #+#             */
/*   Updated: 2017/10/24 18:37:26 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_keys(t_all *all)
{
	if (all->draw->w == 800 && all->draw->h == 800)
	{
		mlx_string_put(all->draw->mlx, all->draw->win, 445, 600, 0xffffff,
				"Displacement: up, down, right, left");
		mlx_string_put(all->draw->mlx, all->draw->win, 445, 630, 0xffffff,
				"Depth: -, +");
		mlx_string_put(all->draw->mlx, all->draw->win, 445, 660, 0xffffff,
				"Zoom: mouse wheel");
		mlx_string_put(all->draw->mlx, all->draw->win, 445, 690, 0xffffff,
				"Change parameter of the Julia set:");
		mlx_string_put(all->draw->mlx, all->draw->win, 445, 710, 0xffffff,
				"start: space, stop: enter");
		mlx_string_put(all->draw->mlx, all->draw->win, 445, 740, 0xffffff,
				"Change colors: black&white - 'A',");
		mlx_string_put(all->draw->mlx, all->draw->win, 445, 760, 0xffffff,
				"colorful - 'S'");
	}
}

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
	if (ac < 2 || ac > 2)
		show_usage(all);
	else if (av[1][0] == '1' && av[1][1] == '\0')
		all->draw->fractal = 1;
	else if (av[1][0] == '2' && av[1][1] == '\0')
		all->draw->fractal = 2;
	else if (av[1][0] == '3' && av[1][1] == '\0')
		all->draw->fractal = 3;
	else
		show_usage(all);
}

int		main(int ac, char **av)
{
	t_all *all;

	all = init_all();
	check_fractal(all, av, ac);
	if (all->draw->error == 1)
	{
		clean_all(all);
		return (0);
	}
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

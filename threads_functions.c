/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:42:42 by tshevchu          #+#    #+#             */
/*   Updated: 2017/10/24 16:43:39 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thread_first(void *data)
{
	t_all	*all;
	int		i;
	int		j;

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
	t_all	*all;
	int		j;
	int		i;

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
	t_all	*all;
	int		j;
	int		i;

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
	t_all	*all;
	int		j;
	int		i;

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
	t_all	*all;
	int		i;
	int		j;

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

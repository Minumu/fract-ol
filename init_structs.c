/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:20:04 by tshevchu          #+#    #+#             */
/*   Updated: 2017/10/24 16:20:27 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract			*init_fract(void)
{
	t_fract *fract;

	fract = malloc(sizeof(t_fract));
	fract->depth = 500;
	fract->dep = NULL;
	fract->julc_r = -0.8;
	fract->julc_im = -0.156;
	fract->zoom = 0.8;
	fract->move_x = 0.0;
	fract->move_y = 0.0;
	fract->jul_shape = 0;
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
	draw->error = 0;
	draw->fractal = 0;
	draw->w = 800;
	draw->h = 800;
	draw->color = COLORFUL;
	return (draw);
}

t_all			*init_all(void)
{
	t_all *all;

	all = malloc(sizeof(t_all));
	all->draw = init_draw();
	all->fract = init_fract();
	return (all);
}

void			clean_all(t_all *all)
{
	free(all->draw);
	if (all->fract->dep != NULL)
		ft_strdel(&all->fract->dep);
	free(all->fract);
	free(all);
}

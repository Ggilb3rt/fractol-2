/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:44:02 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/28 17:01:58 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fract_color(int ac, char **av, t_fractal *fractal)
{
	if (ac > MINIMUM_USER_ARG)
		fractal->color_mode = av[2];
	else
		fractal->color_mode = "basic";
}

void	set_fract_type(char *av, t_fractal *fractal)
{
	fractal->type = av;
}

void	set_fract_visibility(t_fractal *f)
{
	f->x_min = -1.00;
	f->x_max = 1.00;
	f->y_min = -1.00;
	f->range = f->x_max - f->x_min;
	f->dot_size = f->range / WIN_W;
	f->pixel_size = WIN_W / f->range;
	f->y_max = f->y_min + WIN_H * f->dot_size;
}

void	initialise_fractal(int ac, char **av, t_fractal *fractal)
{
	set_fract_color(ac, av, fractal);
	set_fract_type(av[1], fractal);
	set_fract_visibility(fractal);
}

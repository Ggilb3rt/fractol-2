/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:44:02 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 11:55:41 by ggilbert         ###   ########.fr       */
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

char	*get_fract_type(t_fractal *fractal)
{
	return (fractal->type);
}

void	set_fract_visibility(t_fractal *f) //? put xminmax ymin has arg to use with scroll hook
{
	if (f->type[0] == 'j')
	{
		f->x_min = -2.00;
		f->x_max = 2.00;
		f->y_min = -2.00;
		f->c = -0.8 + 0.156 * I;
	}
	else if (f->type[0] == 'm')
	{
		f->x_min = -2.00;
		f->x_max = 2.00;
		f->y_min = -2.00;
		f->z = 0.00;
	}
	f->range = f->x_max - f->x_min;
	f->dot_size = f->range / WIN_W;
	f->pixel_size = WIN_W / f->range;
	f->y_max = f->y_min + f->pixel_size / WIN_H;
}

void	initialise_fractal(int ac, char **av, t_fractal *fractal)
{
	set_fract_color(ac, av, fractal);
	set_fract_type(av[1], fractal);
	set_fract_visibility(fractal);
}

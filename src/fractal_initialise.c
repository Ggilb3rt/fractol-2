/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_initialise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:44:02 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/02 14:39:42 by ggilbert         ###   ########.fr       */
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

void	set_axes_initial_position(t_fractal *f)
{
	f->x_max = 2.00;
	f->x_min = -2.00;
	f->y_min = -2.00;
	f->y_max = 2.00;
	recalc_fract_visibl_dep(f);
}

void	set_fract_visibility(t_fractal *f)
{
	if (f->type[0] == 'j')
	{
		set_axes_initial_position(f);
		f->c = -1.417022285618 + 0.0099534 * I;
	}
	else if (f->type[0] == 'm')
	{
		f->x_min = -2.10;
		f->x_max = 0.60;
		f->y_min = -1.20;
		f->y_max = 1.20;
		f->z = 0.00;
	}
	else if (f->type[0] == 'b')
	{
		f->x_min = -1.815010;
		f->x_max = -1.645609;
		f->y_min = -0.104061;
		f->y_max = 0.104061;
		f->z = 0.00;
	}
	recalc_fract_visibl_dep(f);
}

void	change_julia_c_origin(char *av, t_fractal *f)
{
	if (ft_atoi(av) == 1)
		f->c = -0.8 + 0.156 * I;
}

void	initialise_fractal(int ac, char **av, t_fractal *fractal)
{
	set_fract_color(ac, av, fractal);
	fractal->type = av[1];
	set_fract_visibility(fractal);
	if (ac == MINIMUM_USER_ARG + 2 && fractal->type[0] == 'j')
		change_julia_c_origin(av[3], fractal);
}

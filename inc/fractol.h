/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:37:08 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 19:30:07 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../lib/libft/libft.h"
# include <math.h>
# include <complex.h>
# include <stdio.h>
# include <stdarg.h>

# define MINIMUM_USER_ARG 2
# define JULIA_SET "julia"
# define MANDEL_SET "mandelbrot"
# define MAX_ITERATIONS 100
# define ZOOM_SPEED 1.1
# define WIN_W 600
# define WIN_H 600

typedef struct s_fractal
{
	char				*type;
	char				*color_mode;
	long double			x_min;
	long double			x_max;
	long double			y_min;
	long double			y_max;
	long double			range;
	long double			dot_size;
	long double			pixel_size;
	long double complex	z;
	long double complex	c;
}				t_fractal;

t_bool		check_valid_arguments(int ac, char **av, int minimum_arg);
void		initialise_fractal(int ac, char **av, t_fractal *fractal);
char		*get_fract_type(t_fractal *fractal);
long double	fract_calc_iterations(t_fractal *f, long double complex c_or_z0);
void		zoom_in_fract_visibl(t_fractal *f, float weight);
void		zoom_out_fract_visibl(t_fractal *f, float weight);

#endif

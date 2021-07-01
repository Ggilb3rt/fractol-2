/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:37:08 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/01 22:43:49 by ggilbert         ###   ########.fr       */
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
# define COLOR_WAVE_AMPLITUDE 128
# define COLOR_WAVE_CENTER 127
# define MAX_POTENTIAL 2000
# define MAX_ITERATIONS 100
# define ZOOM_SPEED 1.4
# define WIN_W 500
# define WIN_H 500

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
	long double complex	last_z;
}				t_fractal;

t_bool		check_valid_arguments(int ac, char **av, int minimum_arg);
void		initialise_fractal(int ac, char **av, t_fractal *fractal);
char		*get_fract_type(t_fractal *fractal);
long double	fract_calc_iterations(t_fractal *f, long double complex c_or_z0);
void		zoom_in_fract_visibl(t_fractal *f, float weight);
void		zoom_out_fract_visibl(t_fractal *f, float weight);
int			(*select_color_type(char *type))(long double, long double complex);
int			trgb_to_hex(int t, int r, int g, int b);
int			color_rainbow(long double n, long double complex z);
int			color_wtf(long double n, long double complex z);

#endif

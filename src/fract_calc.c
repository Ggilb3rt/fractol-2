/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:30:48 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 11:56:45 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double complex get_z_from_set(t_fractal *f, long double complex c_or_z0)
{
	if (f->type[0] == 'j')
		return (c_or_z0);
	else if (f->type[0] == 'm')
		return (f->z);
	else
		return (0);
}

long double complex get_c_from_set(t_fractal *f, long double complex c_or_z0)
{
	if (f->type[0] == 'j')
		return (f->c);
	else if (f->type[0] == 'm')
		return (c_or_z0);
	else
		return (0);
}

long double	fract_calc_iterations(t_fractal *f, long double complex c_or_z0)
{
	long double complex z;
	long double complex c;
	int	i;

	i = 0;
	z = get_z_from_set(f, c_or_z0);
	c = get_c_from_set(f, c_or_z0);
	while (cabsl(z) <= 2 && i < MAX_ITERATIONS)
	{
		z = z * z + c;
		i++;
	}
	return (i + 1.00 - log(2.00));
}
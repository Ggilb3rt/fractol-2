/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:30:48 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/01 22:50:21 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double complex	get_z_from_set(t_fractal *f, long double complex c_or_z0)
{
	if (f->type[0] == 'j')
		return (c_or_z0);
	else if (f->type[0] == 'm')
		return (f->z);
	else
		return (0);
}

long double complex	get_c_from_set(t_fractal *f, long double complex c_or_z0)
{
	if (f->type[0] == 'j')
		return (f->c);
	else if (f->type[0] == 'm')
		return (c_or_z0);
	else
		return (0);
}

//! can return int ?
long double	fract_calc_iterations(t_fractal *f, long double complex c_or_z0)
{
	long double complex	z;
	long double complex	c;
	int					i;

	i = 0;
	z = get_z_from_set(f, c_or_z0);
	c = get_c_from_set(f, c_or_z0);
	while (i < MAX_ITERATIONS)
	{
		if (cabsl(z) > MAX_POTENTIAL)
			break ;
		if (f->type[0] == 'b')
			//! 𝑧𝑛+1=(|𝑅𝑒(𝑧𝑛)|+𝑖|𝐼𝑚(𝑧𝑛)|)2+𝑐
			z = (cabsl(z) * cabsl(z)) + c;
		else
			z = z * z + c;
		i++;
	}
	f->last_z = z;
	return (i);
}

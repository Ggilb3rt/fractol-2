/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:33:28 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/02 14:39:52 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	burnship_calc_iterations(t_fractal *f, long double complex c)
{
	int					i;
	long double complex	z;
	long double complex	pre_calc;

	i = 0;
	z = 0.00;
	while (i < MAX_ITERATIONS)
	{
		if (cabsl(z) > 2)
			break ;
		pre_calc = fabsl(creall(z)) + I * fabsl(cimagl(z));
		z = pre_calc * pre_calc + c;
		i++;
	}
	f->last_z = z;
	return (i);
}

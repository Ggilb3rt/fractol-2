/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:48:58 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 20:02:38 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Old way to make y_max
** f->y_max = f->y_min + f->pixel_size / WIN_H;
*/
void	recalc_fract_visibl_dep(t_fractal *f)
{
	f->range = f->x_max - f->x_min;
	f->dot_size = f->range / WIN_W;
	f->pixel_size = WIN_W / f->range;
}

void	check_limits(t_fractal *f)
{
	if (f->x_max > __LDBL_MAX__ || isnan(f->x_max) || isinf(f->x_max))
		f->x_max = __LDBL_MAX__;
	if (f->y_max > __LDBL_MAX__ || isnan(f->y_max) || isinf(f->y_max))
		f->y_max = __LDBL_MAX__;
	if (f->x_min < -__LDBL_MAX__ || isnan(f->x_min) || isinf(f->x_min))
		f->x_min = -__LDBL_MAX__;
	if (f->y_min < -__LDBL_MAX__ || isnan(f->y_min) || isinf(f->y_min))
		f->y_min = -__LDBL_MAX__;
}

void	zoom_out_fract_visibl(t_fractal *f, float weight)
{
	f->x_min *= weight;
	f->x_max *= weight;
	f->y_min *= weight;
	f->y_max *= weight;
	check_limits(f);
	recalc_fract_visibl_dep(f);
}

void	zoom_in_fract_visibl(t_fractal *f, float weight)
{
	f->x_min /= weight;
	f->x_max /= weight;
	f->y_min /= weight;
	recalc_fract_visibl_dep(f);
}

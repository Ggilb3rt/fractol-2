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

void	recalc_fract_visibl_dep(t_fractal *f)
{
	f->range = f->x_max - f->x_min;
	f->dot_size = f->range / WIN_W;
	f->pixel_size = WIN_W / f->range;
	//f->y_max = f->y_min + f->pixel_size / WIN_H;
	f->y_max = 2.00;
}

void	zoom_out_fract_visibl(t_fractal *f, float weight)
{
	f->x_min *= weight;
	f->x_max *= weight;
	f->y_min *= weight;
	recalc_fract_visibl_dep(f);
}

void	zoom_in_fract_visibl(t_fractal *f, float weight)
{
	f->x_min /= weight;
	f->x_max /= weight;
	f->y_min /= weight;
	recalc_fract_visibl_dep(f);
}

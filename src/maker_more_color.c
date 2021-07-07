/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker_more_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:17:02 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/01 18:30:25 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_rainbow(long double n, long double complex z)
{
	int		r;
	int		g;
	int		b;
	float	frenquency;

	n = n - (log(log(cabsl(z)))) / log(2);
	frenquency = 0.6;
	r = sin(frenquency * n + 4) * COLOR_WAVE_AMPLITUDE + COLOR_WAVE_CENTER;
	g = sin(frenquency * n + 2) * COLOR_WAVE_AMPLITUDE + COLOR_WAVE_CENTER;
	b = sin(frenquency * n + 0) * COLOR_WAVE_AMPLITUDE + COLOR_WAVE_CENTER;
	return (trgb_to_hex(0, r, g, b));
}

int	color_wtf(long double n, long double complex z)
{
	int			r;
	int			g;
	int			b;
	long double	new_n;

	n = n + 1 - log(log2(fabs(cimag(z))));
	new_n = (1 + cos(2 * M_PI * n)) / 2;
	r = sin(0.8 * n + 0) * COLOR_WAVE_AMPLITUDE + COLOR_WAVE_CENTER;
	g = 200 * new_n;
	b = sin(0.96 * new_n + 2) * COLOR_WAVE_AMPLITUDE + COLOR_WAVE_CENTER;
	return (trgb_to_hex(0, r, g, b));
}

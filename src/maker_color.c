/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 09:30:38 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/01 18:56:40 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	trgb_to_hex(int t, int r, int g, int b)
{
	int	trgb[4];
	int	i;

	trgb[0] = t;
	trgb[1] = r;
	trgb[2] = g;
	trgb[3] = b;
	i = 0;
	while (i < 4)
	{
		if (trgb[i] < 0)
			trgb[i] = 0;
		if (trgb[i] > 255)
			trgb[i] = 255;
		i++;
	}
	return (trgb[0] << 24 | trgb[1] << 16 | trgb[2] << 8 | trgb[3]);
}

int	color_mono(long double n, long double complex z)
{
	int		r;
	int		g;
	int		b;

	n = n + (log(log(cabsl(z)))) / log(2);
	r = 201 * ((1 + cos(2 * M_PI * n)) / 2);
	g = 27 * ((1 + cos(2 * M_PI * n)) / 2);
	b = 28 * ((1 + cos(2 * M_PI * n)) / 2);
	return (trgb_to_hex(0, r, g, b));
}

int	color_basic(long double n, long double complex z)
{
	int	r;
	int	g;
	int	b;

	(void)z;
	r = 150 * MAX_ITERATIONS / n;
	g = 10 * MAX_ITERATIONS / n;
	b = 200 * n / MAX_ITERATIONS;
	return (trgb_to_hex(0, r, g, b));
}

int	color_greyscale(long double n, long double complex z)
{
	float	frenquency;
	int		grey;

	(void)z;
	frenquency = 0.7;
	grey = sin(frenquency * n) * COLOR_WAVE_AMPLITUDE + COLOR_WAVE_CENTER;
	return (trgb_to_hex(0, grey, grey, grey));
}

int	(*select_color_type(char *type))(long double n, long double complex z)
{
	if (type[0] == 'b')
		return (&color_basic);
	if (type[0] == 'm')
		return (&color_mono);
	if (type[0] == 'g')
		return (&color_greyscale);
	if (type[0] == 'r')
		return (&color_rainbow);
	if (type[0] == 'w')
		return (&color_wtf);
	else
		return (&color_basic);
}

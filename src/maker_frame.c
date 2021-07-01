/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 09:29:30 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/01 17:13:18 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "need_both.h"

long double complex	get_good_position(t_fractal *f, int x, int y)
{
	long double complex	pos;

	pos = x / f->pixel_size + f->x_min;
	pos += (y / f->pixel_size + f->y_min) * I;
	return (pos);
}

t_bool	make_frame(t_mlx *mlx, t_fractal *f)
{
	int					x;
	int					y;
	long double			n;
	long double complex	moving_point;
	int					(*color_use)(long double, long double complex);

	x = 0;
	color_use = select_color_type(f->color_mode);
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			moving_point = get_good_position(f, x, y);
			n = fract_calc_iterations(f, moving_point);
			if (n == MAX_ITERATIONS)
				my_mlx_put_pixel(&mlx->frame[1], x, y, 0x00000000);
			else
				my_mlx_put_pixel(&mlx->frame[1], x, y, color_use(n, f->last_z));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frame[1].img, 0, 0);
	return (true);
}

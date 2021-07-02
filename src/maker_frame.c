/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 09:29:30 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/02 14:32:25 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "need_both.h"

long double complex	get_good_position(t_fractal *f, int x, int y)
{
	long double complex	pos;

	pos = f->dot_size * x + f->x_min;
	pos += (f->dot_size * y + f->y_min) * I;
	return (pos);
}

void	select_pixel(int x, int y, long double n, t_mlx *mlx, t_fractal *f)
{
	if (n == MAX_ITERATIONS)
		my_mlx_put_pixel(&mlx->frame[1], x, y, 0x00000000);
	else
		my_mlx_put_pixel(&mlx->frame[1], x, y, color_use(n, f->last_z));
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
			if (f->type[0] == 'b')
				n = burnship_calc_iterations(f, moving_point);
			else
				n = fract_calc_iterations(f, moving_point);
			select_pixel(x, y, mlx, f);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frame[1].img, 0, 0);
	return (true);
}

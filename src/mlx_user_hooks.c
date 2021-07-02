/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_user_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:26:43 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/02 14:39:07 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "need_both.h"

int	mouse_scroll(int key, int x, int y, t_app *app)
{
	(void)x;
	(void)y;
	if (key == KEY_SCROLL_OUT)
	{
		zoom_out_fract_visibl(app->f, ZOOM_SPEED);
		make_frame(app->m, app->f);
	}
	if (key == KEY_SCROLL_IN)
	{
		zoom_in_fract_visibl(app->f, ZOOM_SPEED);
		make_frame(app->m, app->f);
	}
	printf("\nx_max : %Lf\tx_min : %Lf\n", app->f->x_max, app->f->x_min);
	printf("y_max : %Lf\ty_min : %Lf\n", app->f->y_max, app->f->y_min);
	return (1);
}

void	fract_move_visibl(t_fractal *f, int key, float speed)
{
	speed *= f->range;
	if (key == KEY_UP)
	{
		f->y_max = f->y_max + speed;
		f->y_min = f->y_min + speed;
	}
	if (key == KEY_DOWN)
	{
		f->y_max = f->y_max - speed;
		f->y_min = f->y_min - speed;
	}
	if (key == KEY_LEFT)
	{
		f->x_max = f->x_max + speed;
		f->x_min = f->x_min + speed;
	}
	if (key == KEY_RIGHT)
	{
		f->x_max = f->x_max - speed;
		f->x_min = f->x_min - speed;
	}
	printf("\nx_max : %Lf\tx_min : %Lf\n", f->x_max, f->x_min);
	printf("y_max : %Lf\ty_min : %Lf\n", f->y_max, f->y_min);
}

int	deal_key(int keycode, t_app *app)
{
	int	i;

	if (keycode == KEY_ESC)
	{
		i = 0;
		while (i < FRAMES_QUANTITY)
		{
			mlx_destroy_image(app->m->mlx, app->m->frame[i].img);
			i++;
		}
		mlx_destroy_window(app->m->mlx, app->m->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		fract_move_visibl(app->f, keycode, 0.1);
		make_frame(app->m, app->f);
	}
	if (keycode == KEY_S)
	{
		set_axes_initial_position(app->f);
		make_frame(app->m, app->f);
	}
	return (1);
}

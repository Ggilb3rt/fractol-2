/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_user_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:26:43 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 19:29:56 by ggilbert         ###   ########.fr       */
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
	return (1);
}

int	deal_key(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(app->m->mlx, app->m->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_both.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:26:15 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 17:14:21 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEED_BOTH_H
# define NEED_BOTH_H
# include "fractol.h"
# include "mlx_utils.h"

typedef struct s_app
{
	t_fractal	*f;
	t_mlx		*m;
}				t_app;

t_bool	make_frame(t_mlx *mlx, t_fractal *fractal);
int		deal_key(int keycode, t_app *mlx);
int		mouse_scroll(int key, int x, int y, t_app *param);
int		minimize(t_mlx *m);

#endif
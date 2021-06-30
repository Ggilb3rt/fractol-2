/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_user_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:26:43 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 11:57:34 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_utils.h"

int	deal_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	mouse_scroll(int key, void *param)
{
	(void)param;
	if (key == 4)
		ft_putstr_fd("Je scroll out !\n", 1);
	if (key == 5)
		ft_putstr_fd("Je scroll in !\n", 1);
	return (1);
}

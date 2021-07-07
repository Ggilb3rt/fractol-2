/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:47:25 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/01 09:34:26 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "need_both.h"

void	my_mlx_put_pixel(t_img *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length + x * (frame->bpp / 8));
	*(unsigned int *)dst = color;
}

void	initialise_frames(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < FRAMES_QUANTITY)
	{
		mlx->frame[i].img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
		mlx->frame[i].addr = mlx_get_data_addr(mlx->frame[i].img,
				&mlx->frame[i].bpp, &mlx->frame[i].line_length,
				&mlx->frame[i].endian);
		i++;
	}
	mlx->current_frame = 0;
}

void	initialise_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit(EXIT_FAILURE);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "Fractol");
	if (mlx->win == NULL)
		exit(EXIT_FAILURE);
	initialise_frames(mlx);
}

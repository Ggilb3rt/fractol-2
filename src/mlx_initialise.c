/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:47:25 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 16:32:24 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "need_both.h"

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
	mlx->current_frame = i - 1;
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

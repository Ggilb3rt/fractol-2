/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:47:25 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/29 15:26:20 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_utils.h"

int	trgb_to_hex(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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
	int color = trgb_to_hex(0, 255, 0, 255);

	i = 0;
	while (i < FRAMES_QUANTITY)
	{
		mlx->frame[i].img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
		mlx->frame[i].addr = mlx_get_data_addr(mlx->frame[i].img,
				&mlx->frame[i].bpp, &mlx->frame[i].line_length,
				&mlx->frame[i].endian);
		my_mlx_put_pixel(&mlx->frame[i], WIN_W / 2 + i*200, WIN_H / 2, color);
		i++;
	}
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
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frame[0].img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frame[1].img, 0, 0);
}

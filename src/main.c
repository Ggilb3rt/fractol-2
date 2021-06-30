/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:37:08 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 11:42:42 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_utils.h"

void	print_debug(t_fractal fract)
{
	printf("\n%s, %s\n--------", fract.type, fract.color_mode);
	printf("\nx : %Lf, %Lf == %Lf\n", fract.x_min, fract.x_max, fract.range);
	printf("\ny : %Lf, %Lf == %Lf\n", fract.y_min, fract.y_max, fract.range);
	printf("\nPixel size = %Lf\tDot_size = %Lf\n", \
			fract.pixel_size, fract.dot_size);
	printf("Reel position = %Lf\n", (440 / fract.pixel_size + fract.x_min));
	printf("Reel position = %Lf\n", (440 * fract.dot_size + fract.x_min));
}

void	print_help(void)
{
	printf("Something went wrong.\n");
	printf("\nList of fractals :\n\t- julia\n\t- mandelbrot\n");
	printf("\nList of colors :\n\t- basic\n\t- mono\n\t- greyscale\n");
	printf("\nUsage example :\n\t./fractol julia greyscale");
	printf("\nIf no color mode provided, basic will be used");
}

long double complex	get_good_position(t_fractal *f, int x, int y)
{
	long double complex pos;

	pos = x / f->pixel_size + f->x_min;
	pos += (y / f->pixel_size + f->y_min) * I;
	return (pos);
}

t_bool	make_frame(t_mlx *mlx, t_fractal *fractal)
{
	int			x;
	int			y;
	long double	n;
	long double complex	moving_point;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			// selectionner le bon point variable
			moving_point = get_good_position(fractal, x, y);
			// calculer le nombre d'iterations
			n = fract_calc_iterations(fractal, moving_point);
			// selectionner la bonne couleur
			if (n < MAX_ITERATIONS)
				my_mlx_put_pixel(&mlx->frame[1], x, y, 0x0000FF00);
			else
				my_mlx_put_pixel(&mlx->frame[1], x, y, 0x00FF0000);
			// appliquer dans la bonne image
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->frame[1].img, 0, 0);
	return (true);
}

int	main(int ac, char **av)
{
	t_fractal	fract;
	t_mlx		mlx;

	if (!check_valid_arguments(ac, av, MINIMUM_USER_ARG))
	{
		print_help();
		exit(EXIT_FAILURE);
	}
	initialise_fractal(ac, av, &fract);
	print_debug(fract);
	initialise_mlx(&mlx);
	make_frame(&mlx, &fract);
	mlx_key_hook(mlx.win, deal_key, &mlx);
	mlx_hook(mlx.win, 4, 1L << 11, mouse_scroll, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
#include "fractol.h"

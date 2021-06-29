/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:37:08 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/29 15:40:29 by ggilbert         ###   ########.fr       */
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
	mlx_key_hook(mlx.win, deal_key, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

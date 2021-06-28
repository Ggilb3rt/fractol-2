/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:37:08 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/28 16:57:34 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	if (!check_valid_arguments(ac, av, MINIMUM_USER_ARG))
	{
		print_help();
		exit(1);
	}
	initialise_fractal(ac, av, &fract);
	printf("\n%s, %s\n--------", fract.type, fract.color_mode);
	printf("\nx : %Lf, %Lf == %Lf\n", fract.x_min, fract.x_max, fract.range);
	printf("\ny : %Lf, %Lf == %Lf\n", fract.y_min, fract.y_max, fract.range);
	printf("\nPixel size = %Lf\tDot_size = %Lf\n", \
			fract.pixel_size, fract.dot_size);
	printf("Reel position = %Lf\n", (440 / fract.pixel_size + fract.x_min));
	printf("Reel position = %Lf\n", (440 * fract.dot_size + fract.x_min));
	return (0);
}

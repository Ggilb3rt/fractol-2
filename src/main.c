/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:37:08 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/01 19:02:52 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "need_both.h"

void	print_debug(t_fractal fract)
{
	printf("\n%s set, %s\n--------", fract.type, fract.color_mode);
	printf("\nx : %Lf, %Lf == %Lf\n", fract.x_min, fract.x_max, fract.range);
	printf("\ny : %Lf, %Lf == %Lf\n", fract.y_min, fract.y_max, fract.range);
	printf("\nPixel size = %Lf\tDot_size = %Lf\n", \
			fract.pixel_size, fract.dot_size);
	printf("Reel position = %Lf\n", (440 / fract.pixel_size + fract.x_min));
	printf("Reel position = %Lf\n", (440 * fract.dot_size + fract.x_min));
}

void	print_help(void)
{
	printf("Usage :\n-----\n\t./fractol [fractal_type] ([color])\n");
	printf("\nList of fractals :\n\t- julia\n\t- mandelbrot\n");
	printf("\nList of colors :\n\t- basic\n\t- greyscale\n");
	printf("\t- mono\n\t- rainbow\n\t- wtf?\n");
	printf("\nExample :\n-------\n\t./fractol julia rainbow\n");
	printf("\nIf no color mode provided, \"basic\" will be used");
}

int	main(int ac, char **av)
{
	t_fractal	fract;
	t_mlx		mlx;
	t_app		app;

	if (!check_valid_arguments(ac, av, MINIMUM_USER_ARG))
	{
		print_help();
		exit(EXIT_FAILURE);
	}
	app.f = &fract;
	app.m = &mlx;
	initialise_fractal(ac, av, &fract);
	print_debug(fract);
	initialise_mlx(&mlx);
	make_frame(&mlx, &fract);
	mlx_key_hook(mlx.win, deal_key, &app);
	mlx_mouse_hook(mlx.win, mouse_scroll, &app);
	mlx_loop(mlx.mlx);
	return (0);
}

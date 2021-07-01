/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:50:46 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/01 19:02:57 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool	is_arg_valid(char *user_arg, int nb, ...)
{
	va_list	args;
	va_list	copy;
	size_t	arg_l;

	va_start(args, nb);
	va_copy(copy, args);
	while (nb > 0)
	{
		arg_l = ft_strlen(va_arg(copy, char *));
		if (!ft_strncmp(user_arg, va_arg(args, char *), arg_l))
		{
			va_end(args);
			va_end(copy);
			return (true);
		}
		nb--;
	}
	va_end(args);
	va_end(copy);
	return (false);
}

t_bool	check_valid_arguments(int ac, char **av, int minimum_arg)
{
	if (ac < minimum_arg)
		return (false);
	if (!is_arg_valid(av[1], 3, JULIA_SET, MANDEL_SET, "burn"))
		return (false);
	if (ac > minimum_arg)
	{
		if (!is_arg_valid(av[2], 5, "basic", "mono",
				"greyscale", "rainbow", "wtf?"))
			return (false);
	}
	return (true);
}

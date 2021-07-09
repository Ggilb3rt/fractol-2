/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:08:57 by ggilbert          #+#    #+#             */
/*   Updated: 2019/10/23 17:55:24 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*obj;

	if (!count || !size)
		return (ft_strdup(""));
	obj = malloc(count * size);
	if (obj == NULL)
		return (NULL);
	ft_bzero(obj, count * size);
	return (obj);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:40:14 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/30 16:16:47 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H
# include "../lib/libft/libft.h"
# include "../lib/minilibx_opengl/mlx.h"

# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_SCROLL_OUT 4
# define KEY_SCROLL_IN 5
# define FRAMES_QUANTITY 2

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		frame[FRAMES_QUANTITY];
	int			current_frame;
}				t_mlx;

void	initialise_mlx(t_mlx *mlx);
void	my_mlx_put_pixel(t_img *frame, int x, int y, int color);

#endif

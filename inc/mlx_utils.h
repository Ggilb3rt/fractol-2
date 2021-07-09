/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:40:14 by ggilbert          #+#    #+#             */
/*   Updated: 2021/07/02 11:03:53 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H
# include "../lib/libft/libft.h"
# include "../lib/minilibx_opengl/mlx.h"

// LINUX KEYS
# define L_KEY_ESC 65307
# define L_KEY_S 115
# define L_KEY_UP 65362
# define L_KEY_DOWN 65364
# define L_KEY_LEFT 65361
# define L_KEY_RIGHT 65363

//MAC KEYS
# define KEY_ESC 53
# define KEY_S 1
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_LEFT_CLICK 1
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

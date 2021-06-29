/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilbert <ggilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:40:14 by ggilbert          #+#    #+#             */
/*   Updated: 2021/06/29 15:01:36 by ggilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H
# include "../lib/libft/libft.h"
# include "../lib/minilibx_opengl/mlx.h"

# define KEY_ESC 53
# define KEY_SPACE 49
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
}				t_mlx;

int		deal_key(int keycode, t_mlx *mlx);
void	initialise_mlx(t_mlx *mlx);

#endif

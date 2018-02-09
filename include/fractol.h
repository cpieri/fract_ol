/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:15:09 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/09 15:10:53 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"

//# define W_WIDTH	2550
//# define W_HEIGHT	1320
# define W_WIDTH	1000
# define W_HEIGHT	800

typedef struct		s_img
{
	void			*img_s;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			img;
}					t_mlx;

typedef struct		s_com
{
	double			re;
	double			im;
}					t_com;

int					main(int ac, char **av);

#endif

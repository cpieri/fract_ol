/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:41:43 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/27 12:48:23 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_f(int (*f[5])(t_mandel*, int, int, t_mlx*))
{
  f[0] = init_mandelbrot;
  f[1] = init_julia;
  f[2] = init_ship;
  f[3] = init_mandel_2;
  f[4] = init_julia_2;
}

int		init_mandel_2(t_mandel *nb, int x, int y, t_mlx *mlx)
{
	int	col;

	nb->pr = 1.5 * (x - W_WIDTH / 2) / (0.5 * mlx->zoom * W_WIDTH) + mlx->mv.x;
	nb->pi = (y - W_HEIGHT / 2) / (0.5 * mlx->zoom * W_HEIGHT) + mlx->mv.y;
	nb->re = 0.42;
	nb->im = 0.42;
	nb->tmp = 0;
	nb->i = 0;
	col = calc_color(nb, mlx);
	return (col);
}

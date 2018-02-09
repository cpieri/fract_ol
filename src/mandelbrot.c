/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:34:05 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/09 16:36:35 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_mlx *mlx)
{
	int		px = 0;
	int		py = 0;
	double	x;
	double	y;
	double	x1;
	double	y1;
	double 	i = 0;
	double	max_i = 1000;
	double	tmp;
	int		color = 0xFFFFFF;

	x = -2.5;
	y = -1;
	y1 = 0;
	x1 = 0;
	while (py < W_HEIGHT){
		px = 0;
		while (px < W_WIDTH){
			while (((x * x) + (y * y)) < (2 * 2) && i < max_i)
			{
				tmp = (x * x) + (y * y) + x1;
				y = 2 * x * y + y1;
				x = tmp;
				i++;
			}
			color = 50 + i;
			mlx->img.data[(py * mlx->img.size_l / 4) + px] = color;
			px++;
		}
		py++;
	}
}

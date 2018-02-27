/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:41:43 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/27 13:40:48 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int		init_julia_2(t_mandel *nb, int x, int y, t_mlx *mlx)
{
	int	col;

	nb->pr = 0.271543;
	nb->pi = -0.271271;
	nb->re = 1.5 * (x - W_WIDTH / 2) / (0.5 * mlx->zoom * W_WIDTH) + mlx->mv.x;
	nb->im = (y - W_HEIGHT / 2) / (0.5 * mlx->zoom * W_HEIGHT) + mlx->mv.y;
	nb->tmp = 0;
	nb->i = 0;
	col = ship_color(nb, mlx);
	return (col);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:46:41 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/26 09:19:45 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ship_color(t_mandel *nb, t_mlx *mlx)
{
	while ((nb->re * nb->re) + (nb->im * nb->im) < 4 && nb->i < mlx->max_col)
	{
		nb->tmp = (nb->re * nb->re) - (nb->im * nb->im) + nb->pr;
		nb->im = fabs(2 * (nb->re * nb->im) + nb->pi);
		nb->re = fabs(nb->tmp);
		++nb->i;
	}
	if (nb->i < mlx->max_col)
		return (mlx->color[nb->i]);
	return (0);
}

int			init_ship(t_mandel *nb, int x, int y, t_mlx *mlx)
{
	int		col;

	nb->pr = 1.5 * (x - W_WIDTH / 2) / (0.5 * mlx->zoom * W_WIDTH) + mlx->mv.x;
	nb->pi = (y - W_HEIGHT / 2) / (0.5 * mlx->zoom * W_HEIGHT) + mlx->mv.y;
	nb->re = 0;
	nb->im = 0;
	nb->tmp = 0;
	nb->i = 0;
	col = ship_color(nb, mlx);
	return (col);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:34:05 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/15 14:05:02 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		calc_color(t_mandel *nb, t_mlx *mlx)
{
	while (((nb->re * nb->re) + (nb->im * nb->im)) < 4 && nb->i < mlx->max_col)
	{
		nb->tmp = nb->re;
		nb->re = (nb->re * nb->re) - (nb->im * nb->im) + nb->pr;
		nb->im = 2 * (nb->tmp * nb->im) + nb->pi;
		nb->i++;
	}
	if (nb->i < mlx->max_col)
		return (mlx->color[nb->i]);
	return (0);
}

static int		init_julia(t_mandel *nb, int x, int y, t_mlx *mlx)
{
	int	col;

	nb->re = 1.5 * (x - W_WIDTH / 2) / (0.5 * mlx->zoom * W_WIDTH) + mlx->mv.x;
	nb->im = (y - W_HEIGHT / 2) / (0.5 * mlx->zoom * W_HEIGHT) + mlx->mv.y;
	nb->pr = mlx->julia.x;
	nb->pi = mlx->julia.y;
	nb->tmp = 0;
	nb->i = 0;
	col = calc_color(nb, mlx);
	return (col);
}

static int		init_mandelbrot(t_mandel *nb, int x, int y, t_mlx *mlx)
{
	int	col;

	nb->pr = 1.5 * (x - W_WIDTH / 2) / (0.5 * mlx->zoom * W_WIDTH) + mlx->mv.x;
	nb->pi = (y - W_HEIGHT / 2) / (0.5 * mlx->zoom * W_HEIGHT) + mlx->mv.y;
	nb->re = 0;
	nb->im = 0;
	nb->tmp = 0;
	nb->i = 0;
	col = calc_color(nb, mlx);
	return (col);
}

void			*set_fractal(void *init)
{
	t_param		*param;
	t_mandel	nb;
	int			(*f[3])(t_mandel*, int, int, t_mlx*);
	int			col;
	int			x;

	param = (t_param*)init;
	f[0] = init_mandelbrot;
	f[1] = init_julia;
	f[2] = init_ship;
	while (param->y < param->height)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			col = (*f[param->mlx->fractal])(&nb, x, param->y, param->mlx);
			if (col != 0)
				param->mlx->img.data[(param->y * param->mlx->img.size_l / 4)
					+ x] = col;
			x++;
		}
		param->y++;
	}
	pthread_exit(0);
	return (NULL);
}

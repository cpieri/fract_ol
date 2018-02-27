/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:59:28 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/27 09:12:56 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

void	ft_exit(t_mlx *mlx)
{
	free(mlx->color);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img.img_s);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
	free(mlx);
	exit(0);
}

void	reset(t_mlx *mlx)
{
	mlx->zoom = 1;
	mlx->mv.x = (mlx->fractal != 1) ? -0.5 : 0;
	mlx->mv.y = 0;
	free(mlx->color);
	set_color(mlx, 200, 0);
	generate_new_image(mlx);
}

void	ft_free_f(void (*f[5][3])(int, t_mlx*))
{
	int		i;
	int		y;

	i = 0;
	while (i <= 4)
	{
		y = 0;
		while (y <= 1)
			free(f[i][y++]);
		i++;
	}
}

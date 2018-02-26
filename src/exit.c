/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:59:28 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/26 10:02:42 by cpieri           ###   ########.fr       */
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

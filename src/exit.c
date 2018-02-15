/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:59:28 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/15 14:02:25 by cpieri           ###   ########.fr       */
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

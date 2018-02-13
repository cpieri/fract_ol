/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:04:16 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/13 16:13:09 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_new_image(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img_s);
	mlx->img.img_s = mlx_new_image(mlx->mlx, W_WIDTH, W_HEIGHT);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.img_s, &(mlx->img.bpp),
			&(mlx->img.size_l), &(mlx->img.endian));
	thread(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_s, 0, 0);
}

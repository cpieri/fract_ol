/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 07:35:34 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/15 14:05:00 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

int				tracer(int x, int y, void *init)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)init;
	if (mlx->mv_julia == 0)
	{
		mlx->julia.y = (y - W_HEIGHT / 2) / (W_WIDTH - mlx->zoom * 2);
		mlx->julia.x = (x - W_WIDTH / 2) / (W_WIDTH - mlx->zoom * 2);
		generate_new_image(mlx);
		mlx->tmp.x = x;
		mlx->tmp.y = y;
	}
	return (0);
}

int				mouse_event(int button, int x, int y, void *init)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)init;
	if (button == 5)
	{
		mlx->mv.y = (y - W_HEIGHT / 2) / (W_WIDTH - (mlx->zoom + 0.5) * 2);
		mlx->mv.x = (x - W_WIDTH / 2) / (W_WIDTH - (mlx->zoom + 0.5) * 2);
		zoom(0, mlx);
	}
	if (button == 4)
	{
		zoom(1, mlx);
	}
	if (button == 1)
		mlx->mv_julia = (mlx->mv_julia == 0) ? 1 : 0;
	return (0);
}

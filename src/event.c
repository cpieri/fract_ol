/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:29:27 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/14 23:58:22 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

static void		move_re(int av, t_mlx *mlx)
{
	mlx->mv.x += ((av == 0) ? 0.05 : -0.05) / mlx->zoom;
	generate_new_image(mlx);
}

static void		move_im(int av, t_mlx *mlx)
{
	mlx->mv.y += ((av == 0) ? 0.05 : -0.05) / mlx->zoom;
	generate_new_image(mlx);
}

static void		zoom(int av, t_mlx *mlx)
{
	if (av == 1 && mlx->zoom - 0.5 > 0)
		mlx->zoom -= 0.5;
	else if (av == 0)
		mlx->zoom += 0.5;
	generate_new_image(mlx);
}

int				tracer(int x, int y, void *init)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)init;
	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT && mlx->mv_julia == 0)
	{
		mlx->julia.y = (y - W_HEIGHT / 2) / (600 - mlx->zoom * 2);
		mlx->julia.x = (x - W_WIDTH / 2) / (600 - mlx->zoom * 2);
		generate_new_image(mlx);
		mlx->tmp.x = x;
		mlx->tmp.y = y;
		printf("x = %d, y = %d\n", x, y);
	}
	return (0);
}

int				mouse_event(int button, int x, int y, void *init)
{
	t_mlx	*mlx;

	x = 0;
	y = 0;
	mlx = (t_mlx*)init;
	if (button == 5)
	{
		mlx->mv.y = (y / W_HEIGHT - mlx->mv.y) / mlx->zoom;
		mlx->mv.x = (x / W_WIDTH - mlx->mv.x) / mlx->zoom;
		//mlx->mv.x += ((mlx->zoom + 0.5) / 2) - (x / (mlx->zoom + 0.5));
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

int				key_event(int key, void *init)
{
	t_mlx	*mlx;
	void	(*f[4])(int, t_mlx *) = {zoom, move_im, move_re, NULL};

	mlx = (t_mlx*)init;
	if (key == 53)
		exit(0);
	if (key == 69 || key == 24)
		(*f[0])(0, mlx);
	else if (key == 78 || key == 27)
		(*f[0])(1, mlx);
	else if (key == 126)
		(*f[1])(0, mlx);
	else if (key == 125)
		(*f[1])(1, mlx);
	else if (key == 124)
		(*f[2])(0, mlx);
	else if (key == 123)
		(*f[2])(1, mlx);
	return (0);
}

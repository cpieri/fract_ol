/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:29:27 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/12 17:05:50 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

static void		move_re(int av, t_mlx *mlx)
{
	(av == 0) ? mlx->mv.x++ : mlx->mv.x--;
	generate_new_image(mlx);
}

static void		move_im(int	av, t_mlx *mlx)
{
	(av == 0) ? mlx->mv.y++ : mlx->mv.y--;
	generate_new_image(mlx);
}

static void		zoom(int av, t_mlx *mlx)
{
	(av == 0) ? mlx->zoom++ : mlx->zoom--;
	generate_new_image(mlx);
}

int				tracer(int x, int y, void *init)
{
	init = NULL;
	printf("x = %d, y = %d\n", x, y);
	return (0);
}

int				mouse_event(int button, int x, int y, void *init)
{
	t_mlx	*mlx;

	x = 0;
	y = 0;
	mlx = (t_mlx*)init;
	if (button == 5)
		zoom(0, mlx);
	else if (button == 4)
		zoom(1, mlx);
	return (0);
}

int				key_event(int key, void *init)
{
	t_mlx	*mlx;
	void	(*f[4])(int, t_mlx *) = {zoom, move_im, move_re, NULL};

	mlx = (t_mlx*)init;
	//printf("key : %d\n", key);
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

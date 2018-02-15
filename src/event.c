/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:29:27 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/15 12:12:43 by cpieri           ###   ########.fr       */
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

static void		reset(t_mlx *mlx)
{
	mlx->zoom = 1;
	mlx->mv.x = 0;
	mlx->mv.y = 0;
	set_color(mlx, 200, 0);
	generate_new_image(mlx);
}

static int		select_index(int key, int *i)
{
	int		tmp;

	tmp = key;
	if (key == 69 || key == 24 || key == 78 || key == 27)
	{
		if (key == 78 || key == 27)
			*i = 1;
		return (0);
	}
	else if (key == 126 || key == 125)
	{
		if (key == 125)
			*i = 1;
		return (1);
	}
	else if (key == 124 || key == 123)
	{
		if (key == 124)
			*i = 1;
		return (2);
	}
	return (3);
}

int				key_event(int key, void *init)
{
	t_mlx	*mlx;
	int		neg;
	int		index;
	void	(*f[4])(int, t_mlx *);

	f[0] = zoom;
	f[1] = move_im;
	f[2] = move_re;
	f[3] = NULL;
	mlx = (t_mlx*)init;
	neg = 0;
	index = select_index(key, &neg);
	printf("%d\n", key);
	if (index != 3)
		(*f[index])(neg, mlx);
	else if (key == 53)
		exit(0);
	else if (key == 15)
		reset(mlx);
	else if (key == 49)
		mlx->mv_julia = (mlx->mv_julia == 0) ? 1 : 0;
	else if (key == 17 || key == 11 || key == 5
		|| key == 13 || key == 12 || key == 0)
		event_color(key, mlx);
	return (0);
}

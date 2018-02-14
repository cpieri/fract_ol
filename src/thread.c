/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:40:06 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/14 18:25:43 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "fractol.h"

static void		new_param(t_param *param, t_mlx *mlx, int y)
{
	int		max;

	max = W_HEIGHT / MAX_THREAD;
	param->mlx = mlx;
	param->y = y;
	param->height = y + max;
}

int				thread(t_mlx *mlx)
{
	pthread_t	thread[MAX_THREAD];
	t_param		param[MAX_THREAD];
	int			y;
	int			i;

	i = 0;
	y = 0;
	while (i != MAX_THREAD)
	{
		new_param(&param[i], mlx, y);
		pthread_create(&thread[i], NULL, set_fractal, &param[i]);
		y += W_HEIGHT / MAX_THREAD;
		i++;
	}
	while (i >= 0)
		pthread_join(thread[--i], NULL);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:40:06 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/14 08:07:13 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "fractol.h"

int		thread(t_mlx *mlx)
{
	pthread_t	thread[MAX_THREAD];
	t_param		param[MAX_THREAD];
	int			max_y;
	int			i;

	i = 0;
	max_y = W_HEIGHT / MAX_THREAD;
	param[i].mlx = mlx;
	param[i].y = 0;
	param[i].height = max_y;
	pthread_mutex_init(&param[i].mutex, NULL);
	while (i != MAX_THREAD)
	{
		pthread_create(&thread[i], NULL, set_fractal, &param[i]);
		if ((param[i].y + max_y) <= W_HEIGHT && (param[i].height + max_y) <= W_HEIGHT)
		{
			param[i + 1].mlx = mlx;
			param[i + 1].y = param[i].y + max_y;
			param[i + 1].height = param[i].height + max_y;
			pthread_mutex_init(&param[i + 1].mutex, NULL);
		}
		i++;
	}
	while (i >= 0)
		pthread_join(thread[--i], NULL);
	return (0);
}

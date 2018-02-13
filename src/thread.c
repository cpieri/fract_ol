/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:40:06 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/13 20:27:46 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "fractol.h"

int		thread(t_mlx *mlx)
{
	pthread_t	thread[4];
	t_param		param[4];
	int			max_y;
	int			i;

	i = 0;
	max_y = W_HEIGHT / 4;
	param[i].mlx = mlx;
	param[i].y.y = 0;
	param[i].y.height = max_y;
	while (i != 4)
	{
		pthread_create(&thread[i], NULL, set_fractal, &param[i]);
		if ((param[i].y.y + max_y) <= W_HEIGHT && (param[i].y.height + max_y) <= W_HEIGHT)
		{
			param[i].mlx = mlx;
			param[i].y.y += max_y;
			param[i].y.height += max_y;
			//printf("t : %d, y : %d, height : %d\n", t, mlx->y.y, mlx->y.height);
		}
		i++;
	}
	while (i >= 0)
		pthread_join(thread[--i], NULL);
	return (0);
}

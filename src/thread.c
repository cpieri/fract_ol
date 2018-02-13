/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:40:06 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/13 18:10:56 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "fractol.h"

int		thread(t_mlx *mlx)
{
	pthread_t	test[4];
	int			i;
	int			t;
	int			ret;

	i = 0;
	t = W_HEIGHT / 4;
	mlx->y.y = 0;
	mlx->y.height = t;
	while (i != 4)
	{
		ret = pthread_create(&test[i], NULL, set_fractal, mlx);
		if ((mlx->y.y + t) <= W_HEIGHT && (mlx->y.height + t) <= W_HEIGHT)
		{
			mlx->y.y += t;
			mlx->y.height += t;
			printf("t : %d, y : %d, height : %d\n", t, mlx->y.y, mlx->y.height);
		}
		i++;
	}
	while (i >= 0)
		pthread_join(test[--i], NULL);
	return (0);
}

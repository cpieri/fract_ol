/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:40:06 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/13 16:25:29 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "fractol.h"

void	*teste(void	*ok)
{
	ok = NULL;
	//pthread_exit(NULL);
	return NULL;
}

int		thread(t_mlx *mlx)
{
	pthread_t	test[4];
	int			i;
	int			t;
	int			ret;

	i = 0;
	t = W_HEIGHT / 4;
	printf("t : %d\n", t);
	while (i != 4)
	{
		mlx->height = t;
		ret = pthread_create(&test[i], NULL, set_fractal, mlx);
		if (ret == -1){
			perror("fails");
			exit(-1);
		}
		//pthread_join(test[i], NULL);
		i++;
	}
	return (0);
}

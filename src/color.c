/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:44:51 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/27 16:42:15 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static int	check_color(int av)
{
	if (av == 0)
		return (5);
	else if (av == 1)
		return (0x030303);
	else if (av == 2)
		return (0xF00FDF);
	else if (av == 3)
		return (600);
	else if (av == 4)
		return (0x030000);
	else if (av == 5)
		return (0x000300);
	return (2);
}

int			set_color(t_mlx *mlx, int nb, int av)
{
	int		color;
	int		i;
	int		new_col;

	i = 0;
	color = 0x000000;
	new_col = check_color(av);
	if (!(mlx->color = (int*)malloc(sizeof(int) * nb)))
		return (-1);
	while (i != nb)
	{
		mlx->color[i] = color;
		color += new_col * 3;
		i++;
	}
	mlx->max_col = nb;
	return (0);
}

void		event_color(int key, t_mlx *mlx)
{
	int		av;

	av = 0;
	if (key == 17)
		av = 4;
	else if (key == 11)
		av = 0;
	else if (key == 5)
		av = 5;
	else if (key == 13)
		av = 1;
	else if (key == 0)
		av = 2;
	else
		av = 3;
	free(mlx->color);
	set_color(mlx, PRES, av);
	generate_new_image(mlx);
}

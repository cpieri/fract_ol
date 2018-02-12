/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:13:45 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/12 15:52:38 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static void		print_usage(void)
{
	ft_putendl("Usage : ./fractol [julia / mandelbrot]");
	exit(-1);
}

static void		check_arg(char **av)
{
	if (ft_strcmp("mandelbrot", av[1]) != 0 && ft_strcmp("julia", av[1]) != 0)
		print_usage();
	else
		return ;
}

static t_mlx	*init_mlx(t_mlx *init)
{
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, W_WIDTH, W_HEIGHT, "Fract_ol");
	init->img.img_s = mlx_new_image(init->mlx, W_WIDTH, W_HEIGHT);
	init->img.data = (int*)mlx_get_data_addr(init->img.img_s, &(init->img.bpp),
			&(init->img.size_l), &(init->img.endian));
	init->zoom = 1;
	return (init);
}

int				main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
		print_usage();
	check_arg(av);
	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx)))){
		ft_putendl("Mlx malloc failed");
		return (-1);
	}
	mlx = init_mlx(mlx);
	mandelbrot(mlx, 1);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_s, 0, 0);
	mlx_key_hook(mlx->win, key_event, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

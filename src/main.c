/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:13:45 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/27 12:45:44 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static void		print_usage(void)
{
	ft_putendl("Usage : ./fractol :\n[1] : julia\n[2] : mandelbrot\n[3] : ship");
	ft_putendl("[4] : mandel_2\n[5] : julia_2");
	exit(-1);
}

static void		check_arg(char **av, t_mlx *mlx)
{
	if (ft_strcmp("mandelbrot", av[1]) == 0)
		mlx->fractal = 0;
	else if (ft_strcmp("julia", av[1]) == 0)
		mlx->fractal = 1;
	else if (ft_strcmp("ship", av[1]) == 0)
		mlx->fractal = 2;
	else if (ft_strcmp("mandel_2", av[1]) == 0)
			mlx->fractal = 3;
	else if (ft_strcmp("julia_2", av[1]) == 0)
			mlx->fractal = 4;
	else
		print_usage();
	return ;
}

static t_mlx	*init_mlx(t_mlx *init)
{
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, W_WIDTH, W_HEIGHT, "Fract_ol");
	init->img.img_s = mlx_new_image(init->mlx, W_WIDTH, W_HEIGHT);
	init->img.data = (int*)mlx_get_data_addr(init->img.img_s, &(init->img.bpp),
			&(init->img.size_l), &(init->img.endian));
	set_color(init, 200, 0);
	init->zoom = 1;
	init->mv.x = (init->fractal != 1) ? -0.5 : 0;
	init->mv.y = 0;
	init->mv_julia = 0;
	init->julia.x = -0.7;
	init->julia.y = 0.27015;
	return (init);
}

static void		put_img_event(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_s, 0, 0);
	mlx_mouse_hook(mlx->win, mouse_event, mlx);
	mlx_hook(mlx->win, KEYPRESS, KEYPRESSMASK, key_event, mlx);
	mlx_hook(mlx->win, MOTIONNOTIFY, POINTERMOTIONMASK, tracer, mlx);
	mlx_loop(mlx->mlx);
}

int				main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
		print_usage();
	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
	{
		ft_putendl("Mlx malloc failed");
		return (-1);
	}
	check_arg(av, mlx);
	mlx = init_mlx(mlx);
	thread(mlx);
	put_img_event(mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:13:45 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/28 08:54:18 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static void		print_usage(void)
{
	ft_putendl("Usage : ./fractol :\n[0] : mandelbrot\n[1] : julia");
	ft_putendl("[2] : ship\n[3] : mandel_2\n[4] : julia_ship");
	ft_putendl("[5] : multibrot\n[6] : dragon");
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
	else if (ft_strcmp("julia_ship", av[1]) == 0)
		mlx->fractal = 4;
	else if (ft_strcmp("multibrot", av[1]) == 0)
		mlx->fractal = 5;
	else if (ft_strcmp("dragon", av[1]) == 0)
		mlx->fractal = 6;
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
	set_color(init, PRES, 0);
	init->zoom = 1;
	init->mv.x = (init->fractal != 1 && init->fractal != 4
			&& init->fractal != 5 && init->fractal != 6) ? -0.5 : 0;
	init->mv.y = 0;
	init->mv_julia = 0;
	init->julia.x = -0.7;
	init->julia.y = 0.27015;
	return (init);
}

static void		put_img_event(t_mlx *mlx)
{
	ft_putendl("Touch :\n[1] Color : Q, A, W, T, G, B");
	ft_putendl("[2] Zoom : mouse, +, -");
	ft_putendl("[3] Change fractal : 1, 2, 3, 4, 5, 6, 7");
	ft_putendl("[4] Move : up/down, left/right, mouse left/mouse right");
	ft_putendl("[5] Stop julia : space, click left\n[6] Reset : R");
	ft_putendl("[7] Quit : Esc");
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

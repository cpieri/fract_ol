/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:13:45 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/09 09:43:24 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

static void		print_usage(void)
{
	ft_putendl("Usage : ./fractol [julia / mandelbrot]");
	exit(0);
}

static void		check_arg(char **av)
{
	if (ft_strcmp("mandelbrot", av[1]) != 0 && ft_strcmp("julia", av[1]) != 0)
		print_usage();
	else
		return ;
}

int				main(int ac, char **av)
{
	if (ac != 2)
		print_usage();
	check_arg(av);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:15:09 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/14 07:38:54 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"

//# define W_WIDTH	2550
//# define W_HEIGHT	1320
# define W_WIDTH			1000
# define W_HEIGHT			800
# define MAX_THREAD		50
# define MotionNotify		6
# define PointerMotionMask	(1L<<6)

/*
** Struct for new thread
*/

typedef struct		s_height
{
	int				y;
	int				height;
}					t_height;

/*
** All little struct for t_mlx
*/

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_double
{
	double			x;
	double			y;
}					t_double;

typedef struct		s_img
{
	void			*img_s;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

/*
** Principal struct for Mlx, Win, Img, Zoom...
*/

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_point			p;
	t_double		mv;
	double			zoom;
	int				fractal;
}					t_mlx;

/*
** Struct for each thread
*/

typedef struct		s_param
{
	t_mlx			*mlx;
	int				y;
	int				height;
	pthread_mutex_t	mutex;
}					t_param;

/*
**	Struct for calc fractals
*/

typedef struct		s_mandel
{
	double			pr;
	double			pi;
	double			re;
	double			im;
	double			tmp;
	int				i;
}					t_mandel;

void				generate_new_image(t_mlx *mlx);
int					mouse_event(int button, int x, int y, void *init);
int					tracer(int x, int y, void *init);
int					key_event(int key, void *init);
int					main(int ac, char **av);
void				*set_fractal(void *init);
int					thread(t_mlx *mlx);

#endif

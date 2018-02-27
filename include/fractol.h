/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:15:09 by cpieri            #+#    #+#             */
/*   Updated: 2018/02/27 12:47:45 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/includes/libft.h"

# define W_WIDTH			1000
# define W_HEIGHT			800
# define MAX_THREAD			4
# define MOTIONNOTIFY		6
# define KEYPRESS			2
# define KEYPRESSMASK		(1L<<0)
# define POINTERMOTIONMASK	(1L<<6)
# define EXIT				53
# define RESET				15
# define SPACE				49
# define ZOOM_UP			69
# define ZOOM_DOWN			78
# define ZOOM_UP2			24
# define ZOOM_DOWN2			27
# define LEFT				123
# define RIGHT				124
# define UP					125
# define DOWN				126

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

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_point			tmp;
	t_double		mv;
	t_double		julia;
	int				*color;
	int				max_col;
	int				fractal;
	int				mv_julia;
	double			zoom;
}					t_mlx;

typedef struct		s_height
{
	int				y;
	int				height;
}					t_height;

typedef struct		s_param
{
	t_mlx			*mlx;
	int				y;
	int				height;
}					t_param;

typedef struct		s_mandel
{
	double			pr;
	double			pi;
	double			re;
	double			im;
	double			tmp;
	int				i;
}					t_mandel;

int					mouse_event(int button, int x, int y, void *init);
int					tracer(int x, int y, void *init);
int					key_event(int key, void *init);
int					main(int ac, char **av);
int					thread(t_mlx *mlx);
int					init_ship(t_mandel *nb, int x, int y, t_mlx *mlx);
int					set_color(t_mlx *mlx, int nb, int av);
int					calc_color(t_mandel *nb, t_mlx *mlx);
int					init_mandelbrot(t_mandel *nb, int x, int y, t_mlx *mlx);
int					init_julia(t_mandel *nb, int x, int y, t_mlx *mlx);
int					init_mandel_2(t_mandel *nb, int x, int y, t_mlx *mlx);
int					init_julia_2(t_mandel *nb, int x, int y, t_mlx *mlx);
void				init_f(int (*f[4])(t_mandel*, int, int, t_mlx*));
void				*set_fractal(void *init);
void				zoom(int av, t_mlx *mlx);
void				move_re(int av, t_mlx *mlx);
void				event_color(int key, t_mlx *mlx);
void				generate_new_image(t_mlx *mlx);
void				ft_exit(t_mlx *mlx);
void				reset(t_mlx *mlx);
void				ft_free_f(void (*f[5][3])(int, t_mlx*));
t_mlx				*reset_mlx(t_mlx *init);

#endif

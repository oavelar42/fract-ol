/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:01:36 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/13 15:20:21 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1260
# define WIN_HEIGHT 960
# define ZOOM 1.0f
# define THREADS 8

# include "mlx.h"
# include <stdint.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# include <fcntl.h>
# include <pthread.h>
# include "../libft/libft.h"

# if defined(__linux__) || defined(__unix__)
#  define ESC 65307
#  define CLOSE 33
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define NUM_0	65456
#  define DIGIT_1 49
#  define NUM_MULT 65450
#  define NUM_DIV 65455
#  define NUM_PLUS 65451
#  define NUM_MINUS 65453
#  define NUM_ENTER 65421
#  define L 108

# elif __APPLE__
#  define ESC 53
#  define CLOSE 17
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define NUM_0	82
#  define DIGIT_1 18
#  define NUM_MULT 67
#  define NUM_DIV 75
#  define NUM_PLUS 69
#  define NUM_MINUS 78
#  define NUM_ENTER 76
#  define L 37
# endif

typedef struct s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef union u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

typedef struct s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;

typedef struct s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

typedef struct s_complex
{
	double		r;
	double		i;
}					t_complex;

typedef struct s_viewport
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
	t_complex	mouse;
}					t_viewport;

typedef struct s_pixel
{
	t_complex	c;
	long		i;
}					t_pixel;

typedef struct s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}					t_palette;
typedef struct s_mlx	t_mlx;

typedef void	(*t_f_fn_v)(t_viewport *v);
typedef t_pixel	(*t_f_fn_p)(int x, int y, t_viewport *v, t_mlx *mlx);

typedef struct s_fractal
{
	char		*name;
	t_f_fn_v	viewport;
	t_f_fn_p	pixel;
	int			mouse;
}					t_fractal;

typedef struct s_thread
{
	int				id;
	t_mlx			*mlx;
}					t_thread;

typedef struct s_render
{
	pthread_t		threads[THREADS];
	t_thread		args[THREADS];
}					t_render;

struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_fractal	*fractal;
	t_pixel		*data;
	t_image		*image;
	t_mouse		mouse;
	t_viewport	viewport;
	t_palette	*palette;
	t_render	render;
	int			smooth;
	int			mouselock;
};

t_mlx				*mlxdel(t_mlx *mlx);
t_mlx				*init(t_fractal *f);
void				render(t_mlx *mlx);
void				draw(t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
int					hook_expose(t_mlx *mlx);
t_image				*close_image(t_mlx *mlx, t_image *img);
t_image				*new_image(t_mlx *mlx);
void				clear_image(t_image *img);
void				image_set_pixel(t_image *image, int x, int y, int color);
t_fractal			*fractal_match(char *str);
int					get_color(t_pixel p, t_mlx *mlx);
t_palette			*array_colors(void);
void				zoom(int x, int y, t_viewport *v, double z);
void				viewport_fit(t_viewport *v);
void				reset_viewport(t_mlx *mlx);
t_complex			screen_complex(int x, int y, t_viewport *v);
t_pixel				mandelbrot_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				mandelbrot(t_viewport *v);
t_pixel				burningship_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				burningship(t_viewport *v);
t_pixel				julia_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				julia(t_viewport *v);
void				*ft_memalloc(size_t size);
void				ft_free(void **ap);

#endif
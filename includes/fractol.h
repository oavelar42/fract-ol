/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:01:36 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/08 10:29:18 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 960
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
# include "../libft/libft.h"

# if defined(__linux__) || defined(__unix__)
#  define ESC 65307
#  define CLOSE 33
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363

# elif __APPLE__
#  define ESC 53
#  define CLOSE 17
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124


#endif

typedef struct  s_image
{
    void    *image;
    char    *ptr;
    int     bpp;
    int     stride;
    int     endian;
}               t_image;

typedef struct		s_complex
{
	double		r;
	double		i;
}					t_complex;

typedef struct		s_viewport
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

typedef struct		s_pixel
{
	t_complex	c;
	long		i;
}					t_pixel;

typedef struct s_mlx	t_mlx;

typedef void		(*t_f_fn_v)(t_viewport *v);
typedef t_pixel		(*t_f_fn_p)(int x, int y, t_viewport *v, t_mlx *mlx);

typedef struct  s_fractal
{
    char    *name;
    t_f_fn_v	viewport;
	t_f_fn_p	pixel;
}               t_fractal;

typedef struct		s_thread
{
	int				id;
	t_mlx			*mlx;
}					t_thread;

typedef struct		s_render
{
	pthread_t		threads[THREADS];
	t_thread		args[THREADS];
}					t_render;

typedef struct s_mlx
{
    void        *mlx;
    void        *window;
	char    	*img_add;
    t_fractal   *fractal;
    t_pixel     *data;
    t_viewport  viewport;
    t_image     *image;
    t_render    render;
}               t_mlx;

#endif

void        init(t_mlx *mlx);
void        render(t_mlx *mlx);
void	    draw(t_mlx *mlx);
t_image     *del_image(t_mlx *mlx, t_image *img);
void        image_set_pixel(t_image *image, int x, int y, int color);
t_fractal	*fractal_match(char *str);
int			get_color(t_pixel p, t_mlx *mlx);
void		viewport_fit(t_viewport *v);
void		reset_viewport(t_mlx *mlx);
void    	move_element(int key, t_mlx *mlx);
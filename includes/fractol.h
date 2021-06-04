/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:01:36 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/04 14:26:37 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# include <fcntl.h>
# include "libft.h"

# if defined(__linux__) || defined(__unix__)
#  define ESC 65307
#  define CLOSE 33

# elif __APPLE__
#  define ESC 53
#  define CLOSE 17

#endif

typedef struct  s_image
{
    void    *image;
}               t_image;

typedef struct  s_fractal
{
    char    *name;
}               t_fractal;

typedef struct s_mlx
{
    void    *mlx;
    void    *window;
    t_image *image;
}               t_mlx;

#endif
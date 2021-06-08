/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:35:44 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/08 11:24:45 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel     julia_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
    t_complex   z;
    t_complex   c;
    t_complex   dest;
    int         count;

    (void)mlx;
    z = screen_complex(x, y, v);
    c = v->mouse;
    count = 0;
    while (z.r * z.r + z.i * z.i < (1 << 8) && count < v->max)
    {
        dest.r = z.r * z.r - z.i * z.i + c.r;
        dest.i = z.r * z.i * 2 + c.i;
        if (z.r == dest.r && z.i == dest.i)
        {
            count = v->max;
            break ;
        }
        z.r = dest.r;
        z.i = dest.i;
        count++;
    }
    return ((t_pixel){.c = z, .i = count});
}

void		julia_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
}
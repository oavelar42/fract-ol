/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:40:49 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/07 22:50:06 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    viewport_fit(t_viewport *v)
{
    double  w;
    double  h;

    w = v->xmax - v->xmin;
    h = v->ymax - v->ymin;
    if (w / h >= (float) WIN_WIDTH / WIN_HEIGHT)
    {
        v->ymin = -(w * WIN_HEIGHT / WIN_WIDTH / 2);
        v->ymax = w * WIN_HEIGHT / WIN_WIDTH / 2;
    }
    else
    {
        v->xmin = -(h * WIN_WIDTH / WIN_HEIGHT / 2);
        v->xmax = h * WIN_WIDTH / WIN_HEIGHT / 2;
    }
}

void    reset_viewport(t_mlx *mlx)
{
    mlx->viewport.offx = 0;
    mlx->viewport.offy = 0;
    mlx->fractal->viewport(&mlx->viewport);
    viewport_fit(&mlx->viewport);
    mlx->viewport.max = 32;
    mlx->viewport.zoom = 1.0f;
}
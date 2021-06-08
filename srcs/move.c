/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:17:52 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/08 10:22:07 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    move_element(int key, t_mlx *mlx)
{
    double  w;
    double  h;

    w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
    h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
    if (key == UP)
        mlx->viewport.offy -= h * 0.05f;
    if (key == DOWN)
        mlx->viewport.offy += h * 0.05f;
    if (key == LEFT)
        mlx->viewport.offx -= w * 0.05f;
    if (key == RIGHT)
        mlx->viewport.offx += w *0.05f;
    /*if (key == K_L)
        mlx->mouselock = 1 - mlx->mouselock;*/
}
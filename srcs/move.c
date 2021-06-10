/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:17:52 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/10 16:25:50 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(int x, int y, t_viewport *v, double z)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (v->xmax - v->xmin) * (v->zoom);
	h = (v->ymax - v->ymin) * (v->zoom);
	nw = (v->xmax - v->xmin) * (v->zoom * z);
	nh = (v->ymax - v->ymin) * (v->zoom * z);
	v->zoom *= z;
	v->offx -= ((double)x / WIN_WIDTH) * (nw - w);
	v->offy -= ((double)y / WIN_HEIGHT) * (nh - h);
}

int		draw_hooks(int key, t_mlx *mlx)
{
	int		doot;

	doot = 0;
	if (key >= DIGIT_1 && key <= DIGIT_1 + 3)
		mlx->palette = &get_palettes()[key - DIGIT_1];
	else if (key == NUM_ENTER)
		mlx->smooth = 1 - mlx->smooth;
	else
		doot = 1;
	if (!doot)
		draw(mlx);
	return (doot);
}

int		hook_keydown(int key, t_mlx *mlx)
{
	if (key == NUM_0)
		reset_viewport(mlx);
	if (key == NUM_MULT)
		mlx->viewport.max *= 2;
	if (key == NUM_DIV)
		if (mlx->viewport.max / 2 >= 2)
			mlx->viewport.max /= 2;
	if (key == NUM_PLUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, 1 / ZOOM);
	if (key == NUM_MINUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, ZOOM);
	//move_element(key, mlx);
	if (draw_hooks(key, mlx))
		render(mlx);
	return (0);
}

int	move_element(int key, t_mlx *mlx)
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
	if (key == L)
		mlx->mouselock = 1 - mlx->mouselock;
	return (hook_keydown(key, mlx));
}
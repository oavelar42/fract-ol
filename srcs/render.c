/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:33:46 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/07 18:46:24 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void     *render_thread(void *m)
{
	t_thread    *t;
	int         x;
	int         y;

	t = (t_thread *)m;
	y = WIN_HEIGHT / THREADS * t->id;
	while (y < WIN_HEIGHT / THREADS * (t->id + 1))
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			*(t->mlx->data + y * WIN_WIDTH + x) =
				t->mlx->fractal->pixel(x, y, &t->mlx->viewport, t->mlx);
			x++;
		}
		y++;
	}
	return (NULL);
}

void    render(t_mlx *mlx)
{
   int         count;
   t_render    *ren;

   count = 0;
   ren = &mlx->render;
   while (count < THREADS)
   {
	  ren->args[count].id = count;
	  ren->args[count].mlx = mlx;
	  pthread_create(ren->threads + count, NULL, render_thread, &(ren->args[count]));
	  count++;
   }
   count = 0;
   while (count < THREADS)
   {
	  pthread_join(ren->threads[count], NULL);
	  count++;
   }
   draw(mlx);
}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			image_set_pixel(mlx->image, x, y,
				get_color(*(mlx->data + y * WIN_WIDTH + x), mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
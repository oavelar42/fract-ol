/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:05:46 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/13 14:17:04 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_count(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

t_color	ft_rgb(t_color c1, t_color c2, double p)
{
	t_color	c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_count((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_count((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_count((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}

t_color	linear_color(double i, int max, t_palette *p)
{
	double		index;
	double		adjust;
	int			c;

	if (p->cycle)
		index = fmod(i, p->cycle - 1) / (p->cycle - 1);
	else
		index = i / max;
	c = p->count - 1;
	adjust = fmod(index, 1.0f / c) * c;
	return (ft_rgb((t_color)(p->colors[(int)(index * c) + 1]),
		(t_color)(p->colors[(int)(index * c)]),
		(int)(adjust + 1) - adjust));
}

t_color	smooth_color(t_pixel p, int max, t_palette *pal)
{
	double	i;
	double	zn;
	double	nu;

	zn = log(p.c.r * p.c.r + p.c.i * p.c.i) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = p.i + 1 - nu;
	if (i < 0)
		i = 0;
	return (linear_color(i, max, pal));
}

int	get_color(t_pixel p, t_mlx *mlx)
{
	if (p.i >= mlx->viewport.max)
		return (0x000000);
	if (mlx->smooth)
		return (smooth_color(p, mlx->viewport.max, mlx->palette).value);
	return (linear_color((double)p.i, mlx->viewport.max, mlx->palette).value);
}

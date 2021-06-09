/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 23:05:46 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/09 17:06:33 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

t_color	clerp(t_color c1, t_color c2, double p)
{
	t_color c;
	
	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}

t_color	linear_color(double i, int max, t_palette *p)
{
	double	index;
	double	adj;
	int		count;

	if (p->cycle)
		index = fmod(count, p->cycle - 1) / (p->cycle - 1);
	else
		index = count / max;
	count = p->count - 1;
	adj = fmod(index, 1.0f / count) * count;
	return (clerp((t_color)(p->colors[(int)(index * count) + 1]),
		(t_color)(p->colors[(int)(index * count)]),
		(int)(adj + 1) - adj));
}

t_color		smooth_color(t_pixel p, int max, t_palette *palet)
{
	double	i;
	double	z;
	double	n;

	z = log(p.c.r * p.c.r + p.c.i * p.c.i) / 2.0f;
	n = log(z / log(2)) / log(2);
	i = p.i + 1 - n;
	if (i < 0)
		i = 0;
	return (linear_color(i, max, palet));
}

int get_color(t_pixel p, t_mlx *mlx)
{
	if (p.i >= mlx->viewport.max)
		return (0x000000);
	if (mlx->smooth)
		return (smooth_color(p, mlx->viewport.max, mlx->palette).value);
	return (linear_color((double)p.i, mlx->viewport.max, mlx->palette).value);
}
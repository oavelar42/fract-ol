/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:09:53 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/10 14:45:29 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_set_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_WIDTH)
		return ;
	*(int *)(mlx->ptr + ((x + y * WIN_WIDTH) * mlx->bpp)) = color;
}

t_mlx *del_image(t_mlx *mlx)
{
	if (mlx->image != NULL)
	{
		if (mlx->image != NULL)
			mlx_destroy_image(mlx->mlx, mlx->image);
		free(mlx->image);
	}
	return (NULL);
}
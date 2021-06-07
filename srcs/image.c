/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:09:53 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/07 14:16:07 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image *del_image(t_mlx *mlx, t_image *img)
{
    if (img != NULL)
    {
        if (img->image != NULL)
            mlx_destroy_image(mlx->mlx, img->image);
        free(img);
    }
    return (NULL);
}
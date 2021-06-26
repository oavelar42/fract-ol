/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:02:04 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/13 14:20:44 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

t_mlx	*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->image != NULL)
		close_image(mlx, mlx->image);
	ft_free((void **)&mlx);
	return (NULL);
}

t_mlx	*init(t_fractal *f)
{
	t_mlx	*mlx;
	char	*title;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	title = ft_strjoin("Fract'ol - ", f->name);
	if ((mlx->mlx = mlx_init()) == NULL || (mlx->window =
		mlx_new_window(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT, title)) == NULL
			    || (mlx->image = new_image(mlx)) == NULL
			    || (mlx->data = ft_memalloc(sizeof(t_pixel) * WIN_WIDTH
			    * WIN_HEIGHT)) == NULL)
	return (mlxdel(mlx));
	mlx->mouse.isdown = 0;
	mlx->fractal = f;
	mlx->mouselock = 1 - f->mouse;
	mlx->palette = array_colors();
	mlx->smooth = 1;
	return (mlx);
}

t_image	*new_image(t_mlx *mlx)
{
	t_image		*img;

	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (close_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
			&img->endian);
	img->bpp /= 8;
	return (img);
}

t_palette	*array_colors(void)
{
	static t_palette	array[5];

	array[0]
		= (t_palette){5, 0, {0x4B4FC5, 0xB30032, 0xFFB733, 0xF57336, 0xC22121}};
	array[1]
		= (t_palette){5, 0, {0x0D1C33, 0x3DC51B, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[2]
		= (t_palette){5, 0, {0x002F2F, 0xFFF64D, 0xEFECCA, 0xA7A37E, 0xE6E2AF}};
	array[3]
		= (t_palette){7, 10, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
		0x0000FF, 0xFF00FF, 0xFF0000}};
	array[4] = (t_palette){0, 0, {0}};
	return (array);
}

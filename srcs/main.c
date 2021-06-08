/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:51:43 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/08 10:31:35 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	del_image(mlx, mlx->image);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		printf("\n\nClosed with ESC\n");
		close_program(mlx);
	}
	if (keycode == RIGHT || keycode == LEFT || keycode == UP || keycode == DOWN)
		move_element(keycode, mlx);
	return (0);
}

void	push_image(t_mlx *mlx)
{
	render(mlx);
	mlx_clear_window(mlx->mlx, mlx->window);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
}

void	init(t_mlx *mlx)
{
	t_image	image;

	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract'ol");
	mlx->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img_add = mlx_get_data_addr(mlx->image, &image.bpp, &image.stride, &image.endian);
	mlx_hook(mlx->window, CLOSE, 0L, close_program, mlx);
	mlx_key_hook(mlx->window, key_hook, mlx);
	//mlx_expose_hook(mlx->window, push_image, mlx);
	push_image(mlx);
	mlx_loop(mlx->mlx);
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_fractal	*f;

	if (ac < 2)
		printf("\nERROR : not enough arguments\n");
	f = fractal_match(av[1]);
	if (f->name == NULL)
		printf("\nInvalid fractal name\n");
	init(&mlx);
	reset_viewport(&mlx);
	close_program(&mlx);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:51:43 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/04 14:36:37 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	scene_quit(mlx);
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
	else if (mlx == 1)
		push_image(mlx);
	return (1);
}

void	push_image(t_mlx *mlx)
{
	render(mlx);
	mlx_clear_window(mlx->mlx, mlx->window);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
}

int	main(int ac, char **av)
{
	t_mlx		*mlx;
	t_fractal	*f;

	if (ac < 2)
		printf("\nERROR : not enough arguments\n");
	f = fractal_match(av[1]);
	if (f->name == NULL)
		printf("\nInvalid fractal name\n");
	if ((mlx = init(f)) == NULL)
		printf("\nMLX couldn't init\n");
	reset_vierport(mlx);
	render(mlx);
	mlx_hook(mlx->window, CLOSE, 0L, close_program, mlx);
	mlx_key_hook(mlx->window, key_hook, mlx);
	mlx_expose_hook(mlx->window, push_image, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
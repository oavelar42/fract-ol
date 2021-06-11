/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:51:43 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/11 22:23:58 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractal	*f;

	if (argc < 2)
		return (printf("ERROR: <fractol> <name>"));
	f = fractal_match(argv[1]);
	if (f->name == NULL)
		return (printf("Are you sure that is the name of the fractol?"));
	mlx = NULL;
	if (mlx != NULL)
		return (printf("ERROR: you have a problem somewhere !"));
	else
		mlx = init(f);
	reset_viewport(mlx);
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

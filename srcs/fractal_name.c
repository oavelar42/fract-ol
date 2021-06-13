/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:31:43 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/13 14:12:20 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*get_fractals(void)
{
	static t_fractal	array[8] = {
		{"mandelbrot", mandelbrot, mandelbrot_pixel, 0},
		{"julia", julia, julia_pixel, 1},
		{"burningship", burningship, burningship_pixel, 0},
		{NULL, NULL, NULL, 0}
	};

	return (array);
}

t_fractal	*fractal_match(char *str)
{
	t_fractal	*f;
	int			i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}

void	ft_free(void **ap)
{
	free(*ap);
	*ap = (NULL);
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

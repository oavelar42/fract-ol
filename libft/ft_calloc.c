/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:07:18 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 13:21:17 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	total;
	size_t	i;

	total = count * size;
	res = (void *)malloc(total);
	if (!res)
		return (NULL);
	i = 0;
	while (i < total)
		res[i++] = 0;
	return ((void *)res);
}

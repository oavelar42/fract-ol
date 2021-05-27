/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:00:14 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:22:02 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*result;

	if (!dst && !src)
		return (0);
	result = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			(*(char*)--dst) = (*(char*)--src);
	}
	else
		while (len--)
			(*(char *)dst++) = (*(char *)src++);
	return (result);
}

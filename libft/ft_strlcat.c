/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:20:21 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:39:04 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (len_src + size);
	while (*dest)
		dest++;
	count = 0;
	while ((count + len_dest + 1 < size) && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (len_dest + len_src);
}

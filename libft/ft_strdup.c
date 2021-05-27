/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:12:53 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:36:06 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		count;
	int		count_dest;

	count = 0;
	count_dest = 0;
	while (src[count])
		count++;
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (0);
	while (src[count_dest])
	{
		ptr[count_dest] = src[count_dest];
		count_dest++;
	}
	ptr[count_dest] = '\0';
	return (ptr);
}

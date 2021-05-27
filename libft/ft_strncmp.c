/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:45:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/02/25 11:46:10 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (!n)
		return (0);
	while ((s1[count] == s2[count] && s1[count] && s2[count]) && n > count + 1)
		count++;
	return (((unsigned char *)s1)[count] - ((unsigned char *)s2)[count]);
}

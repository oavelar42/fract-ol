/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:16:26 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:37:11 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		count;
	int		count2;
	int		len_s1;
	int		len_s2;

	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	ptr = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ptr)
		return (0);
	count = 0;
	count2 = 0;
	while (s1[count])
		ptr[count2++] = s1[count++];
	count = 0;
	while (s2[count])
		ptr[count2++] = s2[count++];
	ptr[count2] = '\0';
	return (ptr);
}

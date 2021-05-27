/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:21:30 by oavelar           #+#    #+#             */
/*   Updated: 2021/04/10 14:41:26 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*trim;
	int		i;

	start = 0;
	while (s1[start] && my_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > 0 && my_set(s1[end], set))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	trim = (char *)malloc(sizeof(char) * (end + 2 - start));
	if (!trim)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = 0;
	return (trim);
}
